/* Copyright (c) 2012 BlackBerry Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "connect4app.h"

#include <bb/cascades/Container>
#include <bb/cascades/Control>
#include <bb/cascades/ImageView>
#include <bb/cascades/Page>
#include <bb/cascades/QmlDocument>

class Thread : public QThread
{
public:
    static void msleep(int ms)
    {
        QThread::msleep(ms);
    }
};

connect4App::~connect4App()
{
}

connect4App::connect4App()
{

    // Create and Load the QMLDocument, using build patterns.
    QmlDocument *qml = QmlDocument::create("asset:///main.qml");

    if (!qml->hasErrors()) {

        //setNumMoves(0);
        mNumTiles = 6;
        player = 1;
        setVicMsg("Please select number of players");

        // Set the context property we want to use from inside the QML file. Functions exposed
        // via Q_INVOKABLE will be found with the property and the name of the function.
        qml->setContextProperty("connect4", this);

        // The application Page is created from the QML file.
        mAppPage = qml->createRootObject<Page>();

        findPlayAreaAndInitialize(mAppPage);

        if (mAppPage) {
            // Finally the main scene for the application is set to the Page.
            Application::instance()->setScene(mAppPage);
        }
    }
}

void connect4App::resetTiles()
{
    // Reset the tiles.
    findPlayAreaAndInitialize(mAppPage);

    // Enable the screen
    for (int i = 0; i < 7; i++)
    {
    	for (int ii = 0; ii < 6; ii++)
    	{
    		mPlayField[i][ii]->blockSignals(false);
    	}
    }
}

void connect4App::setNumTiles(int in)
{
    // This function is called from the QML file.
    // The integer passed in to checked for range, in case we're outside the grid.
    if (in > 0 && in < 32) {
        mNumTiles = in;
    }

}

/*void connect4App::checkAndChangeTile(int i, int ii, const QString &tileName)
{
    // Check the tile.
    if (i != -1 && ii != -1) {
        if (i != mNumTiles) {
            if (ii != mNumTiles) {

                // Get the object name (actually the image name which is easy to identify).
                QVariant v = mPlayField[i][ii]->objectName();

                if (v.canConvert<QString>()) {
                    QString objName = v.value<QString>();

                    if (objName.contains(tileName, Qt::CaseInsensitive)) {
                        mPlayField[i][ii]->setObjectName("isTurned");
                        mPlayField[i][ii]->setImage(Image(QUrl("asset:///images/empty.png")));

                        // If we find a tile to change, we check the surrounding tiles also.
                        checkNeighboursAndChange(i, ii, tileName);
                    }
                }
            }
        }
    }
}

void connect4App::checkNeighboursAndChange(int i, int ii, const QString &tileName)
{
    // Check the neighbors of the selected tile.
    checkAndChangeTile(i - 1, ii, tileName);
    checkAndChangeTile(i + 1, ii, tileName);
    checkAndChangeTile(i, ii - 1, tileName);
    checkAndChangeTile(i, ii + 1, tileName);
}

void connect4App::checkPlayAreaAndChange(const QString &msg)
{
    // Loop through the whole play area to check the neighbors of this tile.
    if (mPlayAreaContainer) {
        for (int i = 0; i < mNumTiles; i++) {
            for (int ii = 0; ii < mNumTiles; ii++) {
                if (mPlayField[i][ii]->objectName() == "isTurned") {
                    checkNeighboursAndChange(i, ii, msg);
                }
            }
        }
    }
}
*/

void connect4App::findPlayAreaAndInitialize(Page *appPage)
{
    bool connectResult;
    Q_UNUSED(connectResult);

    // Find where we want to add our tiles.
    mPlayAreaContainer = appPage->findChild<Container*>("playArea");

    // Reset the play area by removing all the tile images.
    mPlayAreaContainer->removeAll();

    // As long as nothing is broken, we continue.
    if (mPlayAreaContainer) {

        // Calculate the size of the tiles
        mWantedSize = mPlayAreaContainer->preferredWidth() / (mNumTiles +1);

        // Iterate through all the tiles.
        for (int i = 0; i < mNumTiles + 1; i++) {
            Container* columnContainer = new Container();
            int tileNum = 0;

            for (int ii = 0; ii < mNumTiles; ii++) {

            	tileNum++;

                ImageView *imageView = ImageView::create()
                            .bottomMargin(0).topMargin(0).leftMargin(0).rightMargin(0);
                imageView->setPreferredSize(mWantedSize, mWantedSize);

                QString imageSource = QString("asset:///images/empty.png");
                imageView->setImage(Image(imageSource));

                // We are connecting all our tiles to the same slot, we can later identify them by sender().
                connectResult = connect(imageView, SIGNAL(touch(bb::cascades::TouchEvent *)), this,
                        SLOT(onTileTouch(bb::cascades::TouchEvent *)));
                Q_ASSERT(connectResult);

                // Keep track of the ImageView.
                mPlayField[i][ii] = imageView;
                if (tileNum == 6){
                	mPlayField[i][ii]->setObjectName(imageSource + "isBottom");
                                }
                else {
                	mPlayField[i][ii]->setObjectName(imageSource);
                }
                imageView->blockSignals(true);
                columnContainer->add(imageView);
            }

            mPlayAreaContainer->add(columnContainer);
        }
    }
}


bool connect4App::horizontalWin(int player, int i, int ii)
{
	int connected = 1;

	int m = i + 1;
	while (true)
	{
		if (m > 6)
		{
			break;
		}

		if (mPlayField[m][ii]->objectName() == QString("tile%1").arg(player))
		{
			connected++;
			m = m + 1;
		}
		else
		{
			break;
		}
	}

	m = i - 1;
	while (true)
	{
		if (m < 0)
		{
			break;
		}
		if (mPlayField[m][ii]->objectName() == QString("tile%1").arg(player))
		{
			connected++;
			m = m - 1;
		}
		else
		{
			break;
		}
	}
	return (connected >= 4);
}
bool connect4App::verticalWin(int player, int i, int ii)
{
	int connected = 1;

	int n = ii + 1;
	while (true)
	{
		if (n > 5)
		{
			break;
		}
		if (mPlayField[i][n]->objectName() == QString("tile%1").arg(player))
		{
			connected++;
			n = n + 1;
		}
		else
		{
			break;
		}
	}

	n = ii - 1;
	while (true)
	{
		if (n < 0)
		{
			break;
		}
		if (mPlayField[i][n]->objectName() == QString("tile%1").arg(player))
		{
			connected++;
			n = n - 1;
		}
		else
		{
			break;
		}
	}
	return (connected >= 4);
}
bool connect4App::rDiagonalWin(int player, int i, int ii)
{
	int connected = 1;

	int m = i + 1;
	int n = ii + 1;
	while (true)
	{
		if (m > 6 || n > 5)
		{
			break;
		}
		if (mPlayField[m][n]->objectName() == QString("tile%1").arg(player))
		{
			connected++;
			m = m + 1;
			n = n + 1;
		}
		else
		{
			break;
		}
	}

	m = i - 1;
	n = ii - 1;
	while (true)
	{
		if (m < 0 || n < 0)
		{
			break;
		}
		if (mPlayField[m][n]->objectName() == QString("tile%1").arg(player))
		{
			connected++;
			m = m - 1;
			n = n - 1;
		}
		else
		{
			break;
		}
	}
	return (connected >= 4);

}
bool connect4App::lDiagonalWin(int player, int i, int ii)
{
	int connected = 1;

	int m = i + 1;
	int n = ii - 1;
	while (true)
	{
		if (m > 6 || n < 0)
		{
			break;
		}
		if (mPlayField[m][n]->objectName() == QString("tile%1").arg(player))
		{
			connected++;
			m = m + 1;
			n = n - 1;
		}
		else
		{
			break;
		}
	}

	m = i - 1;
	n = ii + 1;
	while (true)
	{
		if (m < 0 || n > 5)
		{
			break;
		}
		if (mPlayField[m][n]->objectName() == QString("tile%1").arg(player))
		{
			connected++;
			m = m - 1;
			n = n + 1;
		}
		else
		{
			break;
		}
	}
	return (connected >= 4);
}

bool connect4App::isVictory(int player, int i, int ii)
{
	if ( verticalWin(player, i ,ii) || horizontalWin(player, i ,ii) || rDiagonalWin(player, i ,ii) || lDiagonalWin(player, i ,ii) )
	{
		return true;
	}
	return false;
}

//1 Player or 2 Players
void connect4App::setMode(int m)
{
	mode = m;
}

//Which player is next to move?
void connect4App::setPlayer(int p)
{
	player = p;
}

//Displays message beneath title
void connect4App::setVicMsg (const QString msg)
{
    if (msg != mVicMsg) {
        mVicMsg = msg;
        emit vicMsgChanged();
    }
}

QString connect4App::vicMsg()
{
	return mVicMsg;
}

//Drops piece to the bottom of the touched column if it's not filled
void connect4App::checkAndChangeIfValid(int i, int ii){
	if (ii > 5){
		return;
	}
	QVariant v = mPlayField[i][ii]->objectName();

	if (v.canConvert<QString>()) {
		QString objName = v.value<QString>();
		//If the play slot is empty and is the most bottom of the empty column
		if (objName.contains("empty") && objName.contains("Bottom") ) {
			//If it's player 1's turn, change tile to Red (tile1)
			if (player == 1)
	        {
				mPlayField[i][ii]->setImage(Image(QUrl("asset:///images/tile1.png")));
				mPlayField[i][ii]->setObjectName("tile1");

				//If the play slot isn't the very top one, change the slot above it to "Bottomempty" so it can be recognized as the next valid slot
				if (ii > 0)
				{
					mPlayField[i][ii - 1]->setObjectName("Bottomempty");
				}

				//If this move wins, disable playing field and display victory message
				if (isVictory(player, i, ii))
				{
					setVicMsg(QString("Player %1 wins!").arg(player));
					for (int i = 0; i < 7; i++)
						{
							for (int ii = 0; ii < 6; ii++)
							{
								mPlayField[i][ii]->blockSignals(true);
							}
						}
					return;
				}

				//If board is full, disable playing field and display tie message
				if (isDraw())
				{
					setVicMsg(QString("It's a tie!"));
					for (int i = 0; i < 7; i++)
					{
						for (int ii = 0; ii < 6; ii++)
						{
							mPlayField[i][ii]->blockSignals(true);
						}
					}
					return;
				}

				//Set the next player to move to player 2
				setVicMsg("Player 2 to move");
				player = 2;

				//If there is only one player playing, make a computer move
				if (mode == 1)
				{
				    int y = 0;
				    int x = 0;
				    QVariant q;
				    QString name;
				    do {
				    	x = rand() % 7;
				    	q = mPlayField[x][y]->objectName();
				    	name = q.value<QString>();

				    } while ((name.contains("tile")));

				    checkAndChangeIfValid(x, y);
				    return;
				}
	        }
	        else //if it's player 2's turn
	        {
	        	//Thread::msleep(2000);
	        	mPlayField[i][ii]->setImage(Image(QUrl("asset:///images/tile2.png")));
	            mPlayField[i][ii]->setObjectName("tile2");

	            if (ii > 0)
	            {
	            	mPlayField[i][ii - 1]->setObjectName("Bottomempty");
	            }

	            //If this move wins, disable playing field and display victory message
	            if (isVictory(player, i, ii))
	            {
	            	setVicMsg(QString("Player %1 wins!").arg(player));
	            	for (int i = 0; i < 7; i++)
	            	{
	            		for (int ii = 0; ii < 6; ii++)
	            		{
	            			mPlayField[i][ii]->blockSignals(true);
	            		}
	            	}
	            	return;
	            }

	        	if (isDraw())
	        	{
	        		setVicMsg(QString("It's a tie!"));
	        		for (int i = 0; i < 7; i++)
	        		{
	        			for (int ii = 0; ii < 6; ii++)
	        			{
	        				mPlayField[i][ii]->blockSignals(true);
	        			}
	        		}
	        		return;
	        	}

	        	setVicMsg("Player 1 to move");
	            player = 1;
	        }

	    }
	    else //if the touched slot is not the bottom one, recurse to the bottom of the board
	    {
	    	checkAndChangeIfValid(i, ii + 1);
	    }
	}
}

bool connect4App::isDraw()
{
	QVariant v;
	QString objName;

	for (int x = 0; x < 7; x++)
	{
		v = mPlayField[x][0]->objectName();
		objName = v.value<QString>();
		if (!(objName.contains("tile")))
		{
			return false;
		}
	}
	return true;
}

void connect4App::onTileTouch(bb::cascades::TouchEvent *event)
{
    // If we have a touch-down on a tile.
    if (event->isDown()) {

        // Find who sent it.
        ImageView* senderImage = dynamic_cast<ImageView*>(sender());

        if (senderImage != NULL) {

            // If that container is real, we iterate through all the tiles.
            for (int i = 0; i < mNumTiles + 1; i++) {
                for (int ii = 0; ii < mNumTiles; ii++) {

                    // Try and find our saved pointer to a tile.
                    if (mPlayField[i][ii] == senderImage) {

                    	//Checks to see if move is valid, and do move if so
                    	checkAndChangeIfValid(i, ii);

                         }
                } // Inner loop
            } // Outer loop
        } // if statement
    } // if statement
} // onTileTouch
