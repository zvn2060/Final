var enemyData = 
[
  // 0~5 100 wave 1
  {}, {}, {},
  {}, {}, {},

  // 6~8 400 wave 2
  {},
  {},
  {},

  // 9 1000 wave 3
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

  // 10 1400 wave 4
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

  // 11 2000 boss stage 1
  {
    count: 2000,
    bossStage: "start",
    sprite: "th10_momiji.png",
    hp: 400,
    dialogueA: [
      "???： 「發財」",
      "???： 「發大財」",
      "???： 「糕熊發大財」"
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

  // 12 2000 boss stage 2
  {
    count: 2000,
    bossStage: "stage2",
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

  },

  // 13 2000 boss stage 3
  {
    count: 2000,
    bossStage: "end",
    sprite: "th10_momiji.png",
    hp: 500,
    timeLimit: 2700,
    s: [],
    v: [
      { count:    0, type: "linear", interval: 50, x1:  300, x2:    0, y1:  150, y2:    0 },
      { count:  900, type: "loop", index: 0 }
    ]
  },

  // 14 15 wave 1 after boss
  {
    count: 3000,
    sprite: "yousei_2.png",
    hp: 100,
    x: 90,
    y: -40,
    items: ["s", "s", "p", "p", "s", "s", "s", "s", "L"],
    s: [
        { count:  45, genre: 6, color: 1, bullet: 51, aiming: true, angle: 0, random: 0, offset_r: 0, offset_t: 0 },
        { count:  55, genre: 6, color: 1, bullet: 52, aiming: true, angle: 0, random: 0, offset_r: 0, offset_t: 0 },
        { count:  65, genre: 6, color: 1, bullet: 53, aiming: true, angle: 0, random: 0, offset_r: 0, offset_t: 0 },
        { count:  75, genre: 6, color: 1, bullet: 54, aiming: true, angle: 0, random: 0, offset_r: 0, offset_t: 0 },
        { count:  85, genre: 6, color: 1, bullet: 55, aiming: true, angle: 0, random: 0, offset_r: 0, offset_t: 0 }
    ],
    v: [
      { count:    0, r: 350, angle:   0, ra: -12, w:   0, raa: 0.2 },
      { count:   40, r:   0, angle:   0, ra:   0, w:   0, raa:   0 },
      { count:   90, r: 100, angle:   0, ra:   0, w:   0, raa:   0 }
    ]
  },
  {
    count: 3100,
    sprite: "yousei_2.png",
    hp: 100,
    x: 390,
    y: -40,
    items: ["s", "s", "p", "p", "s", "s", "s", "s", "L"],
    s: [
        { count:  45, genre: 6, color: 1, bullet: 51, aiming: true, angle: 0, random: 0, offset_r: 0, offset_t: 0 },
        { count:  55, genre: 6, color: 1, bullet: 52, aiming: true, angle: 0, random: 0, offset_r: 0, offset_t: 0 },
        { count:  65, genre: 6, color: 1, bullet: 53, aiming: true, angle: 0, random: 0, offset_r: 0, offset_t: 0 },
        { count:  75, genre: 6, color: 1, bullet: 54, aiming: true, angle: 0, random: 0, offset_r: 0, offset_t: 0 },
        { count:  85, genre: 6, color: 1, bullet: 55, aiming: true, angle: 0, random: 0, offset_r: 0, offset_t: 0 }
    ],
    v: [
      { count:    0, r: 350, angle:   0, ra: -12, w:   0, raa: 0.2 },
      { count:   40, r:   0, angle:   0, ra:   0, w:   0, raa:   0 },
      { count:   90, r: 100, angle:   0, ra:   0, w:   0, raa:   0 }
    ]
  },

  // 16 17 wave 2 after boss
  {
    count: 3250,
    sprite: "yousei_2.png",
    hp: 100,
    x: 240,
    y: -40,
    items: ["s", "s", "p", "p", "s", "s", "s", "s", "L"],
    s: [
        { count:  45, genre: 1, color: 6, bullet: 56, aiming: true, angle: 0, random: 5, offset_r: 0, offset_t: 0 }
    ],
    v: [
      { count:    0, r: 250, angle:   0, ra:  -8, w: -0.9, raa: 0.2 },
      { count:   50, r: 999, angle: 999, ra:   0, w:    0, raa:   0 }
    ]
  },
  {
    count: 3350,
    sprite: "yousei_2.png",
    hp: 100,
    x: 240,
    y: -40,
    items: ["s", "s", "p", "p", "s", "s", "s", "s", "L"],
    s: [
        { count:  45, genre: 1, color: 6, bullet: 57, aiming: true, angle: 0, random: 5, offset_r: 0, offset_t: 0 }
    ],
    v: [
      { count:    0, r: 250, angle:   0, ra:  -8, w:  0.9, raa: 0.2 },
      { count:   50, r: 999, angle: 999, ra:   0, w:    0, raa:   0 }
    ]
  },

  // 18 wave 3 after boss
  {
    count: 3450,
    sprite: "yousei_3.png",
    hp: 100,
    x: 240,
    y: -40,
    items: ["s", "s", "p", "p", "s", "s", "s", "s", "L"],
    s: [
    ],
    v: [
      { count:    0, r: 300, angle:   0, ra:  -8, w:    0, raa: 0.2 },
      { count:   45, r:   0, angle:   0, ra:   0, w:    0, raa:   0 },
      { count:  200, r: 100, angle: 180, ra:   0, w:    0, raa:   0 }
    ]
  },

  // 19 wave 4 after boss
  {
    count: 3700,
    sprite: "yousei_4.png",
    hp: 100,
    x: 520,
    y: 100,
    items: ["s", "s", "p", "L", "s", "P"],
    s: [
      { count:  80, genre: 3, color: 2, bullet: 57, aiming: true, angle:    0, random:  5, offset_r: 0, offset_t: 0 },
      { count: 100, genre: 3, color: 2, bullet: 57, aiming: true, angle:    0, random:  5, offset_r: 0, offset_t: 0 },
      { count: 120, genre: 3, color: 2, bullet: 57, aiming: true, angle:    0, random:  5, offset_r: 0, offset_t: 0 },
      { count: 140, genre: 3, color: 2, bullet: 57, aiming: true, angle:    0, random:  5, offset_r: 0, offset_t: 0 },
      { count: 160, genre: 3, color: 2, bullet: 57, aiming: true, angle:    0, random:  5, offset_r: 0, offset_t: 0 },
      { count: 180, genre: 3, color: 2, bullet: 57, aiming: true, angle:    0, random:  5, offset_r: 0, offset_t: 0 },
      { count: 200, genre: 3, color: 2, bullet: 57, aiming: true, angle:    0, random:  5, offset_r: 0, offset_t: 0 },
      { count: 220, genre: 3, color: 2, bullet: 57, aiming: true, angle:    0, random:  5, offset_r: 0, offset_t: 0 }
    ],
    v: [
      { count:    0, r:  300, angle:  -90, ra:  -10, w:   0, raa:  0.15 },
      { count:   60, r:    0, angle:    0, ra:    0, w:   0, raa:  0 },
      { count:  300, r:   90, angle: -135, ra:    0, w:   0, raa:  0 }
    ]
  },
];


// wave 1
for(let i = 0 ; i < 3 ; i++){
  enemyData[2 * i] =
      {
        count: 100 + 40 * i, sprite: "yousei_1.png", hp: 100, x: 180, y: -40,
        items: ["s", "s", "s", "s", "s"],
        s: [
          // boolean in s is now supported
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
        s: [],
        v: [
          { count:    0, r:  60, angle:   0, ra:   0, w:   0, raa:   0 },
          { count:  200, r:  60, angle:   0, ra:   0, w:   1, raa:   0 },
          { count:  300, r:  60, angle: 999, ra:   0, w:   0, raa:   0 }
        ]
      };
  for(let line = 1 ; line <= 5 ; line ++ ){
    for(let wave = 0 ; wave < 5 ; wave++) {
      enemyData[2 * i]["s"].push(
          {count: 100 + 10 * wave, genre: 0, color: 0, bullet: 4, aiming: true, angle: 10 * (3 - line), random: 0, offset_r: 0, offset_t: 0}
      );
      enemyData[2 * i + 1]["s"].push(
          {count: 100 + 10 * wave, genre: 0, color: 0, bullet: 4, aiming: true, angle: -10 * (3 - line), random: 0, offset_r: 0, offset_t: 0}
      )
    }
  }
}


// wave 2
for(let c = 6; c <= 8;c++) {
  enemyData[c] =
      {
        count: 400,
        sprite: "yousei_2.png",
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
  for (let i = 0; i <= 45; i++) {
    enemyData[c]["s"].push({
      count: 210 + i * 2,
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

// boss stage3 shot behavior

var wave_count = [
  [50, 150],
  [300, 400],
  [550, 650],
];

for(let big_wave = 0 ; big_wave < 3 ; big_wave++){
  for(let small_wave = 0; small_wave < 2 ; small_wave++) {
    enemyData[13]["s"].push(
        {count: wave_count[big_wave][small_wave], genre: 8, color: 6, bullet: 5, aiming: false, angle: 0, random: 0, offset_r: 100 * big_wave, offset_t: (small_wave + 1) * 25},
        {count: wave_count[big_wave][small_wave], genre: 8, color: 6, bullet: 5, aiming: false, angle: 0, random: 0, offset_r: 100 * big_wave, offset_t: (small_wave + 1) * -25},
    )
  }
}




// wave 3 after boss
for(let i = 0; i < 50; i++){
  enemyData[18].s.push(
    { count: 60 + i * 2, genre: 2, color: 5, bullet: 58, aiming: false, angle: 0, random: 180, offset_r: 0, offset_t: 0 }
  )
}


console.log(JSON.stringify(enemyData, null, 0));

var t = document.createElement("textarea");
t.value = JSON.stringify(enemyData, null, 0);
document.body.appendChild(t);
t.select();
document.execCommand("copy");
document.body.removeChild(t);


// JSON.stringify(enemyData, null, 2);