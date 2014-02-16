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
import bb.cascades 1.2

Page {
    Menu.definition: MenuDefinition{
        helpAction: HelpActionItem {
            onTriggered: {
                helpSheet.open();
            }
        }
    }
    
    Container {
        topPadding: 110
        background: backgroundPaint.imagePaint
        attachedObjects: [
            ImagePaintDefinition {
                id: backgroundPaint
                imageSource: "asset:///images/background.png"
            }
        ]

        // connect4 Title Label
        Label {
            horizontalAlignment: HorizontalAlignment.Center
            text: "CONNECT 4"
            textStyle.base: appDefaultBigText.style
        }
        
        // Move Count Label
        Label {
            id: propertytime
            horizontalAlignment: HorizontalAlignment.Center

            // connect4.numMoves is a property that we keep track on in cpp code
            // every time it's changed the text will be updated.
            text: connect4.vicMsg;
            topMargin: 40            
            textStyle.base: appDefaultTitleText.style
        }

        // Group the container's player area, a background and a nice flare on top.
        Container {
            topMargin: 80
            horizontalAlignment: HorizontalAlignment.Center
               
            layout: DockLayout {
            }

            // This container is the one we find from CPP and add all the tiles to
            // It's so much easier to do that from C++.
            Container {
                objectName: "playArea"
                id: playArea
                layout: StackLayout {
                    orientation: LayoutOrientation.LeftToRight
                }

                // The dark gray is an awesome trick, we can use it to see where we put our player area when layouting.
                background: Color.DarkGray
                preferredWidth: 724
                preferredHeight: preferredWidth * 6 / 7     
                
                
            }
        }
        
        // Container for simple/complex mode buttons
        Container {
            topMargin: 40
            horizontalAlignment: HorizontalAlignment.Center
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }

            // These buttons will call the C++ code to generate new play fields.
            // You can alter the size of the grid, go ahead and try it!
            Button {
                text: "1 Player"
                imageSource: "asset:///images/icon_1player.png"
                onClicked: {
                    connect4.setNumTiles(6);
                    connect4.resetTiles();
                    connect4.setMode(1);
                    connect4.setPlayer(1);
                    connect4.setVicMsg("Player 1 to move");
                }
            }
            Button {
                text: "2 Players"
                imageSource: "asset:///images/icon_2players.png"
                onClicked: {
                    connect4.setNumTiles(6);
                    connect4.resetTiles();
                    connect4.setMode(2);
                    connect4.setPlayer(1);
                    connect4.setVicMsg("Player 1 to move");           
                }
            }// Button
        }// Container
    }// Main Container
    
    attachedObjects: [
        TextStyleDefinition {
            id: appDefaultBigText
            base: SystemDefaults.TextStyles.BigText
            fontWeight: FontWeight.Bold
            color: Color.create("#E6E9F8")
        },
        TextStyleDefinition {
            id: appDefaultTitleText
            base: SystemDefaults.TextStyles.TitleText
            fontWeight: FontWeight.Bold
            color: Color.create("#E6E9F8")
        }        
        ,
        Sheet {
            id: helpSheet
            content: HelpScreen {}
        }
    ]
}// Page
