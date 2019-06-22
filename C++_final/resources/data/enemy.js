var enemyData = 
[
  // 100 wave 1
  {}, {}, {},
  {}, {}, {},

  // 400 wave 2
  {},
  {},
  {},

  // 1000 wave 3
  {
    count: 1000,
    sprite: "yousei_1.png",
    hp: 100,
    x: 150,
    y: -40,
    items: ["s", "s", "s", "s", "s", "P"],
    s: [
      { count: 140, genre: 3, color: 2, bullet: 1, aiming: true, angle:    0, random: 0, offset_r: 0, offset_t: 0 },
      { count: 160, genre: 3, color: 2, bullet: 1, aiming: true, angle:    0, random: 0, offset_r: 0, offset_t: 0 },
      { count: 180, genre: 3, color: 2, bullet: 1, aiming: true, angle:    0, random: 0, offset_r: 0, offset_t: 0 },
      { count: 200, genre: 3, color: 2, bullet: 1, aiming: true, angle:    0, random: 0, offset_r: 0, offset_t: 0 },
      { count: 220, genre: 3, color: 2, bullet: 1, aiming: true, angle:    0, random: 0, offset_r: 0, offset_t: 0 },
      { count: 240, genre: 3, color: 2, bullet: 1, aiming: true, angle:    0, random: 0, offset_r: 0, offset_t: 0 },
      { count: 260, genre: 3, color: 2, bullet: 1, aiming: true, angle:    0, random: 0, offset_r: 0, offset_t: 0 },
      { count: 280, genre: 3, color: 2, bullet: 1, aiming: true, angle:    0, random: 0, offset_r: 0, offset_t: 0 }
    ],
    v: [
      { count:    0, r:  60, angle:   0, ra:   0, w:   0, raa:   0 },
      { count:  120, r:   0, angle:   0, ra:   0, w:   0, raa:   0 },
      { count:  340, r:  60, angle: 180, ra:   0, w:   0, raa:   0 }
    ]
  },

  // 1400 wave 4
  {
    count: 1400,
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

  // 2000 boss 1
  {
    count: 2000,
    bossStage: true,
    sprite: "th10_momiji.png",
    hp: 400,
    dialogueA: [
      "AA： 「final寫完了嗎?」",
      "BB： 「還沒」",
      "AA： 「快去寫」" 
    ],

    timeLimit: 600,
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

  },

  // 1900 boss-2
  {
    count: 2000,
    bossStage: true,
    sprite: "th10_momiji.png",
    hp: 500,
    timeLimit: 600,
    s: [
      { count:   30, genre: 8, color: 6, bullet: 1, aiming: true, angle:    0, random:  0, offset_r:    0, offset_t:    0 },
      { count:   50, genre: 8, color: 6, bullet: 1, aiming: true, angle:    0, random:  0, offset_r:    0, offset_t:    0 },
    ],
    v: [
      { count:    0, type: "random", interval: 100, x1:  100, x2:  540, y1:   50, y2:  250 },
      { count:  200, type: "loop", index: 0 }
    ]

  }
];


// wave 1
for(let i = 0 ; i < 3 ; i++){
  enemyData[2 * i] =
      {
        count: 100 + 40 * i, sprite: "yousei_1.png", hp: 100, x: 180, y: -40,
        items: ["s", "s", "s", "s", "s"],
        s: [
          // boolean in s is now supported
          { count: 100, genre: 0, color: 0, bullet: 4, aiming: true, angle:    0, random: 0, offset_r: 0, offset_t: 0 },
          { count: 110, genre: 0, color: 0, bullet: 4, aiming: true, angle:    0, random: 0, offset_r: 0, offset_t: 0 },
          { count: 120, genre: 0, color: 0, bullet: 4, aiming: true, angle:    0, random: 0, offset_r: 0, offset_t: 0 },
          { count: 130, genre: 0, color: 0, bullet: 4, aiming: true, angle:    0, random: 0, offset_r: 0, offset_t: 0 },
          { count: 140, genre: 0, color: 0, bullet: 4, aiming: true, angle:    0, random: 0, offset_r: 0, offset_t: 0 }

        ],
        v: [
          { count:    0, r:  60, angle:   0, ra:   0, w:   0, raa:   0 },
          { count:  200, r:  60, angle:   0, ra:   0, w:  -1, raa:   0 },
          { count:  300, r:  60, angle: 999, ra:   0, w:   0, raa:   0 }
        ]
      };
  enemyData[2 * i + 1] =
      {
        count: 100 + 40 * i, sprite: "yousei_1.png", hp: 100, x: 300, y: -40,
        items: ["s", "s", "s", "s", "s"],
        s: [
          // boolean in s is now supported
          { count: 100, genre: 0, color: 0, bullet: 4, aiming: true, angle:    0, random: 0, offset_r: 0, offset_t: 0 },
          { count: 110, genre: 0, color: 0, bullet: 4, aiming: true, angle:    0, random: 0, offset_r: 0, offset_t: 0 },
          { count: 120, genre: 0, color: 0, bullet: 4, aiming: true, angle:    0, random: 0, offset_r: 0, offset_t: 0 },
          { count: 130, genre: 0, color: 0, bullet: 4, aiming: true, angle:    0, random: 0, offset_r: 0, offset_t: 0 },
          { count: 140, genre: 0, color: 0, bullet: 4, aiming: true, angle:    0, random: 0, offset_r: 0, offset_t: 0 }
        ],
        v: [
          { count:    0, r:  60, angle:   0, ra:   0, w:   0, raa:   0 },
          { count:  200, r:  60, angle:   0, ra:   0, w:   1, raa:   0 },
          { count:  300, r:  60, angle: 999, ra:   0, w:   0, raa:   0 }
        ]
      };
}


// wave 2
for(let c = 6; c <= 8;c++) {
  enemyData[c] =
      {
        count: 400,
        sprite: "yousei_1.png",
        hp: 100,
        x: 240 + 100 * ( c - 7 ),
        y: -40,
        items: ["p", "s", "p", "s", "s"],
        s: [],
        v: [
          { count:    0, r:  60, angle:   0, ra:   0, w:   0, raa:   0 },
          { count:  200, r:   0, angle:   0, ra:   0, w:   0, raa:   0 },
          { count:  310, r:  60, angle: 180, ra:   0, w:   0, raa:   0 }
        ]
      };
  for (let i = 0; i <= 18; i++) {
    enemyData[c]["s"].push({
      count: 210 + i * 5,
      genre: 1,
      color: i % 6,
      bullet: 3,
      aiming: true,
      angle: 5 * i,
      random: 0,
      offset_r: 0,
      offset_t: 0
    });
  }
}


console.log(JSON.stringify(enemyData, null, 0));

var t = document.createElement("textarea");
t.value = JSON.stringify(enemyData, null, 0);
document.body.appendChild(t);
t.select();
document.execCommand("copy");
document.body.removeChild(t);


// JSON.stringify(enemyData, null, 2);