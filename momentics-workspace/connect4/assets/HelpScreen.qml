import bb.cascades 1.2

Page {

    
    titleBar: TitleBar {
        dismissAction: ActionItem {
            title: "Back"
            onTriggered: {
                helpSheet.close();
            }
        }
    }
    
        ScrollView {
            scrollViewProperties.scrollMode: ScrollMode.Vertical
            
            Container {
        
        //layout: StackLayout {}
        Label {
            text: qsTr("Tap a column to drop a piece to the bottom.")
            textStyle.base: SystemDefaults.TextStyles.BigText
            verticalAlignment: VerticalAlignment.Center
            horizontalAlignment: HorizontalAlignment.Center
            multiline: true
        }
        ImageView{
            imageSource: "asset:///images/HelpTap.png"
            preferredHeight: 1280
            preferredWidth: 768
        }
        ImageView{
            imageSource: "asset:///images/Help1.png"
            preferredHeight: 1280
            preferredWidth: 768
        
        }
        Label {
            text: qsTr("Connect 4 to win!")
            textStyle.base: SystemDefaults.TextStyles.BigText
            verticalAlignment: VerticalAlignment.Center
            horizontalAlignment: HorizontalAlignment.Center
            multiline: true
        }
        ImageView{
            imageSource: "asset:///images/HelpWin.png"
            preferredHeight: 1280
            preferredWidth: 768
        
        }
    }
}}
