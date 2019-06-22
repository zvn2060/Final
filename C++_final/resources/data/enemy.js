var enemyData = 
[
  // 0: showcase
  {
    count: 100,
    sprite: "yousei_1.png",
    hp: 100,
    x: 180,
    y: -40,
    items: ["s", "s", "s", "s", "s"],
    s: [
      // boolean in s is now supported
      { count: 100, genre: 0, color: 0, bullet: 0, aiming: true, angle:    0, random: 5, offset_r: 0, offset_t: 0 },
      { count: 120, genre: 0, color: 0, bullet: 0, aiming: true, angle:    0, random: 5, offset_r: 0, offset_t: 0 },
      { count: 140, genre: 0, color: 0, bullet: 0, aiming: true, angle:    0, random: 5, offset_r: 0, offset_t: 0 },
      { count: 160, genre: 0, color: 0, bullet: 0, aiming: true, angle:    0, random: 5, offset_r: 0, offset_t: 0 },
      { count: 180, genre: 0, color: 0, bullet: 0, aiming: true, angle:    0, random: 5, offset_r: 0, offset_t: 0 },
      { count: 200, genre: 0, color: 0, bullet: 0, aiming: true, angle:    0, random: 5, offset_r: 0, offset_t: 0 },
      { count: 220, genre: 0, color: 0, bullet: 0, aiming: true, angle:    0, random: 5, offset_r: 0, offset_t: 0 },
      { count: 240, genre: 0, color: 0, bullet: 0, aiming: true, angle:    0, random: 5, offset_r: 0, offset_t: 0 }
    ],
    v: [
      { count:    0, r:  60, angle:   0, ra:   0, w:   0, raa:   0 },
      { count:  200, r:  60, angle:   0, ra:   0, w:  -1, raa:   0 },
      { count:  300, r:  60, angle: 999, ra:   0, w:   0, raa:   0 }
    ]
  },

  // 1: showcase
  {
    count: 400,
    sprite: "yousei_1.png",
    hp: 100,
    x: 300,
    y: -40,
    items: ["p", "s", "p", "s", "s"],
    s: [
      { count: 100, genre: 1, color: 0, bullet: 0, aiming: true, angle:    0, random: 0,  offset_r: 0, offset_t: 0 },
      { count: 120, genre: 1, color: 1, bullet: 0, aiming: true, angle:    0, random: 0,  offset_r: 0, offset_t: 0 },
      { count: 140, genre: 1, color: 2, bullet: 0, aiming: true, angle:    0, random: 0,  offset_r: 0, offset_t: 0 },
      { count: 160, genre: 1, color: 3, bullet: 0, aiming: true, angle:    0, random: 0,  offset_r: 0, offset_t: 0 },
      { count: 180, genre: 1, color: 4, bullet: 0, aiming: true, angle:    0, random: 0,  offset_r: 0, offset_t: 0 },
      { count: 200, genre: 1, color: 5, bullet: 0, aiming: true, angle:    0, random: 0,  offset_r: 0, offset_t: 0 },
      { count: 220, genre: 1, color: 6, bullet: 0, aiming: true, angle:    0, random: 0,  offset_r: 0, offset_t: 0 },
      { count: 240, genre: 1, color: 7, bullet: 0, aiming: true, angle:    0, random: 0,  offset_r: 0, offset_t: 0 }
    ],
    v: [
      { count:    0, r:  60, angle:   0, ra:   0, w:   0, raa:   0 },
      { count:  200, r:  60, angle:   0, ra:   0, w:   1, raa:   0 },
      { count:  300, r:  60, angle: 999, ra:   0, w:   0, raa:   0 }
    ]
  },

  // 2: showcase
  {
    count: 700,
    sprite: "yousei_1.png",
    hp: 100,
    x: 150,
    y: -40,
    items: ["s", "s", "s", "s", "s", "P"],
    s: [
      { count: 140, genre: 1, color: 2, bullet: 1, aiming: true, angle:    0, random: 0, offset_r: 0, offset_t: 0 },
      { count: 160, genre: 1, color: 2, bullet: 1, aiming: true, angle:    0, random: 0, offset_r: 0, offset_t: 0 },
      { count: 180, genre: 1, color: 2, bullet: 1, aiming: true, angle:    0, random: 0, offset_r: 0, offset_t: 0 },
      { count: 200, genre: 1, color: 2, bullet: 1, aiming: true, angle:    0, random: 0, offset_r: 0, offset_t: 0 },
      { count: 220, genre: 1, color: 2, bullet: 1, aiming: true, angle:    0, random: 0, offset_r: 0, offset_t: 0 },
      { count: 240, genre: 1, color: 2, bullet: 1, aiming: true, angle:    0, random: 0, offset_r: 0, offset_t: 0 },
      { count: 260, genre: 1, color: 2, bullet: 1, aiming: true, angle:    0, random: 0, offset_r: 0, offset_t: 0 },
      { count: 280, genre: 1, color: 2, bullet: 1, aiming: true, angle:    0, random: 0, offset_r: 0, offset_t: 0 }
    ],
    v: [
      { count:    0, r:  60, angle:   0, ra:   0, w:   0, raa:   0 },
      { count:  120, r:   0, angle:   0, ra:   0, w:   0, raa:   0 },
      { count:  340, r:  60, angle: 180, ra:   0, w:   0, raa:   0 }
    ]
  },

  // 3: showcase
  {
    count: 1200,
    sprite: "yousei_1.png",
    hp: 100,
    x: 400,
    y: -40,
    items: ["s", "s", "s", "s", "s", "s", "s", "s", "L"],
    s: [
      { count: 140, genre: 1, color: 3, bullet: 2, aiming:false, angle:    0, random:  0, offset_r:  100, offset_t:    0 },
      { count: 150, genre: 1, color: 3, bullet: 2, aiming:false, angle:  -20, random:  0, offset_r:  100, offset_t:  -20 },
      { count: 160, genre: 1, color: 3, bullet: 2, aiming:false, angle:  -40, random:  0, offset_r:  100, offset_t:  -40 },
      { count: 170, genre: 1, color: 3, bullet: 2, aiming:false, angle:  -60, random:  0, offset_r:  100, offset_t:  -60 },
      { count: 180, genre: 1, color: 3, bullet: 2, aiming:false, angle:  -80, random:  0, offset_r:  100, offset_t:  -80 },
      { count: 210, genre: 1, color: 4, bullet: 2, aiming: true, angle:    0, random: 10, offset_r:    0, offset_t:    0 },
      { count: 220, genre: 1, color: 4, bullet: 2, aiming: true, angle:    0, random: 10, offset_r:    0, offset_t:    0 },
      { count: 230, genre: 1, color: 4, bullet: 2, aiming: true, angle:    0, random: 10, offset_r:    0, offset_t:    0 },
      { count: 240, genre: 1, color: 4, bullet: 2, aiming: true, angle:    0, random: 10, offset_r:    0, offset_t:    0 },
      { count: 250, genre: 1, color: 4, bullet: 2, aiming: true, angle:    0, random: 10, offset_r:    0, offset_t:    0 }
    ],
    v: [
      { count:    0, r:  60, angle:   0, ra:   0, w:   0, raa:   0 },
      { count:  120, r:   0, angle:   0, ra:   0, w:   0, raa:   0 },
      { count:  400, r:  60, angle: 180, ra:   0, w:   0, raa:   0 }
    ]
  },

  // 4: showcase boss-1
  {
    count: 1900,
    bossStage: true,
    sprite: "th10_momiji.png",
    hp: 400,
    dialogueA: [
      "AA： 「final寫完了嗎?」",
      "BB： 「還沒」",
      "AA： 「快去寫」" 
    ],

    timeLimit: 1800,
    s: [
      { count:   30, genre: 1, color: 4, bullet: 2, aiming: true, angle:  -40, random:  0, offset_r:    0, offset_t:    0 },
      { count:   35, genre: 1, color: 4, bullet: 2, aiming: true, angle:  -20, random:  0, offset_r:    0, offset_t:    0 },
      { count:   40, genre: 1, color: 4, bullet: 2, aiming: true, angle:    0, random:  0, offset_r:    0, offset_t:    0 },
      { count:   45, genre: 1, color: 4, bullet: 2, aiming: true, angle:   20, random:  0, offset_r:    0, offset_t:    0 },
      { count:   50, genre: 1, color: 4, bullet: 2, aiming: true, angle:   40, random:  0, offset_r:    0, offset_t:    0 },
    ],
    v: [
      { count:    0, type: "random", interval: 100, x1:  100, x2:  540, y1:   50, y2:  250 },
      { count:  120, type: "linear", interval: 100, x1:  200, x2:    0, y1:   50, y2:    0 },
      { count:  240, type: "loop", index: 0 }
    ]

  }
];



console.log(JSON.stringify(enemyData, null, 0));

var t = document.createElement("textarea");
t.value = JSON.stringify(enemyData, null, 0);
document.body.appendChild(t);
t.select();
document.execCommand("copy");
document.body.removeChild(t);


// JSON.stringify(enemyData, null, 2);