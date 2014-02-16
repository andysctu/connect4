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
#ifndef connect4APP_H
#define connect4APP_H

#include <bb/cascades/Application>

using namespace bb::cascades;

namespace bb
{
    namespace cascades
    {
        class Container;
        class ImageView;
        class Page;
        class TouchEvent;
    }
}

/**
 * connect4 description:
 *
 * This is a puzzle game testing you logical skills. The game has some
 * decorative and interaction elements set up in QML, while the actual
 * game board and logics is handled in C++.
 *
 * You will learn how to:
 * - Load part of the UI in QML and part of it in C++.
 * - Dynamically change the part loaded in C++.
 */
class connect4App: public QObject
{
    Q_OBJECT

    /**
     * The numMoves is a property that we want to be able to listen to in the QML file.
     */
    //Q_PROPERTY(int numMoves READ numMoves WRITE setNumMoves NOTIFY numMovesChanged)
    Q_PROPERTY(QString vicMsg READ vicMsg WRITE setVicMsg NOTIFY vicMsgChanged)


public:
    // This is our constructor which sets up the recipe.
    connect4App();
    ~connect4App();

    /**
     * This Invokable function is used for resetting the tile layout from the QML file.
     */
    Q_INVOKABLE void resetTiles();

    /**
     * This Invokable function is used for setting the number of tiles from the QML file.
     * @param numTiles The number of tiles to set
     */
    Q_INVOKABLE void setNumTiles(int numTiles);

    /**
     * This following are getter and setter functions for the numMoves property.
     */
    //void setNumMoves(const int i);
    Q_INVOKABLE void setVicMsg(const QString msg);
    QString vicMsg();
    //int numMoves();
    //Q_INVOKABLE void setVicMsg(QString msg);
    Q_INVOKABLE void setMode(int mode);
    Q_INVOKABLE void setPlayer(int player);

private slots:

    /**
     * This slot is connected to the tiles so we can find out what tiles to turn.
     * @param event The touch event on the tile
     */
    void onTileTouch(bb::cascades::TouchEvent *event);

signals:

    /**
     * This signal is connected to the numMoves property.
     */
    //void numMovesChanged();
	void vicMsgChanged();

private:

    /**
     * Creates the PlayArea with all the tiles, it's the setup function that would be
     * tedious to make in QML, but is easy to make in C++.
     */
    void findPlayAreaAndInitialize(Page *appPage);

    /**
     * These functions initialize the handle and find the tiles that the user presses on.
     * It work like this:
     * First off, when we get a touch on a tile, we check that tile to see what type it is.
     * If its already turned into the neutral tile we do nothing. But if its not,
     * we remember what tile it was and check the whole playArea for turned tiles.
     * Then if we find turned tiles, we check that tile's neighbors for the tiles that
     * look just like the tile that was pressed on. If we find that, we check that ones
     * neighbors. During this process we find the one we originally got a touch on
     * as a turned one.
     */
    //void checkPlayAreaAndChange(const QString &msg);
    //void checkNeighboursAndChange(int i, int ii, const QString &tileName);
    //void checkAndChangeTile(int i, int ii, const QString &tileName);

    void checkAndChangeIfValid(int i, int ii);

    //void AIMoveEasy();

    //check if you won

    bool isVictory(int player, int i, int ii);
    bool isDraw();

    bool horizontalWin(int player, int i, int ii);
    bool verticalWin(int player, int i, int ii);
    bool rDiagonalWin(int player, int i, int ii);
    bool lDiagonalWin(int player, int i, int ii);

    // Some Controls that we need to remember
    Container *mPlayAreaContainer;
    ImageView* mPlayField[32][32]; //32 is the maxSize
    Page *mAppPage;

    // Internal game state variables
    int mNumMoves;
    float mWantedSize;
    float mNumTiles;

    QString mVicMsg;

    int player;
    int mode;

};

#endif // ifndef connect4APP_H
