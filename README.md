Final Project Note
===
# Demo : 6/24
# 模板
* Resource
    管理字型、圖片、音檔，自動控管記憶體

* Game Engine
    管理遊戲視窗、場景、使用者控制事件 

* AudioHelper
    控制音樂撥放的工具類

* FileHelper    (併入Resource ?)
    讀取檔案的工具類

* IScene
    場景 虛擬類 需要繼承並覆寫其中的方法

* IObject
    圖片、圖形控制
    * Image 
        圖片格式
        * Sprite
            圖片操縱精靈
    * Label
        靜態文字物件
    * ImageButton
        可變圖片按鈕    
* IControl
    事件處理

# 專案結構
* Final Project
    * include                       **header folder**
        * Scenes                    **場景**
    * src                           **source folder**
        * Scenes                    **場景**
    * game
        * FinalProject.exe
        * resource                  **resource folder**
    * .gitignore
    * README.md
# TODO
- [X] 聲音設定                (use template)
- [X] 存取檔案                (By Allegro FileIO)
- [X] 允許全螢幕模式
- [X] 雙語言 / Unicode 化     (By Allegro Unicode)
- [X] 支援玩家擴充包           (By Allegro Filesystem)

# Issue


# Bonus
* basic
- [X] Stating Scene
- [X] Use images
- [X] Music and Sound Effect
- [X] Keybord and Mouse
* Functional Bonus
- [X] Animation, Partcle effects
- [X] File save/read (高分榜...)
- [ ] Two Player/Split screens
- [X] Special level design (Super Boss)
- [X] AI of enemy(Hard-coded rules, Q-learning)
- [ ] Physical engine
- [ ] Fun, Creative, Peformace
* Code Bonus
- [X] Git
- [ ] Smart Pointer
- [X] Multi-thread smooth loading (pthread, std::thread…)
- [ ] Online Multiplayer (sockets…)
- [ ] Elegant Coding Style (OOP, Design Patterns…)
- [ ] Try-catch and Lambda function
- [X] Algorithms not covered in this course (A* path finding, Separate-Axis Theorem…)


