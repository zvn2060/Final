var bulletData = 
[
  // 0: showcase
  [],
  // 1: showcase
  [],
  // 2: showcase
  [],
  // 3: showcase flower
  [],
  // 4: showcase single line
  [],
  // 5: offset circle wave
  [],

  // 6~50: bullet data reserved
  [],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],


  // 51 52 53 54 55: wave 1 after boss
  [], [], [], [], [],
  // 56 57: wave 2, 4 after boss
  [], [],
  // 58: wave 3 after boss
  [],
];

for(let i = 1; i <= 4; i++){
  bulletData[0].push([
  	{ count:    0, r:  370, angle:  10 * i, ra:  -12, w:    1, raa:  0.2 },
    { count:   50, r:  999, angle:     999, ra:    0, w:    0, raa:    0 }
  ]);
  bulletData[0].push([
  	{ count:    0, r:  370, angle: -10 * i, ra:  -12, w:   -1, raa:  0.2 },
    { count:   50, r:  999, angle:     999, ra:    0, w:    0, raa:    0 }
  ]);
}


bulletData[1].push([
  { count:    0, r:  360, angle:      0, ra:   -4, w:    0, raa:    0 },
  { count:   50, r:    0, angle:    999, ra:    0, w:    0, raa:    0 },
  { count:   60, r:  140, aiming:  true, ra:    0, w:    0, raa:    0 }
]);

for(let i = 1; i <= 5; i++){
  bulletData[1].push([
    { count:    0, r:  360 - i*10, angle:  10 * i, ra:   -4, w:    0, raa:    0 },
    { count:   50, r:           0, angle:     999, ra:    0, w:    0, raa:    0 },
    { count:   60, r:         140, aiming:   true, ra:    0, w:    0, raa:    0 }
  ]);
  bulletData[1].push([
    { count:    0, r:  360 - i*10, angle: -10 * i, ra:   -4, w:    0, raa:    0 },
    { count:   50, r:           0, angle:     999, ra:    0, w:    0, raa:    0 },
    { count:   60, r:         140, aiming:   true, ra:    0, w:    0, raa:    0 }
  ])
}

for(let i = 1; i <= 12; i++){
  bulletData[2].push([
    { count:    0, r:   30, angle:    0, ra:    1, w:    0, raa:    0, offset_r: 25, offset_t: 30*i },
    { count:   70, r:  999, angle:  999, ra:    0, w:    0, raa:    0 }
  ])
}

for(let i = 0; i <= 3 ; i++){
  bulletData[3].push(
      [
        {count:0, r:370, angle:90 * i, ra:-12, w:0, raa:0.2},
        {count:50, r:50, angle:999, ra:0, w:0, raa:0},
      ]
  )
}


for(let i = 0; i <= 4 ; i++){
  bulletData[4].push(
      [
        {count:0, r:120, angle:0, ra:0, w:0, raa:0},
      ]
  )
}

for(let angle = 0 ; angle <= 360 ; angle += 5){
  bulletData[5].push(
      [
        {count:0, r:180, angle:angle, ra:-12, w:0, raa:0.2},
        {count:10, r:999, angle:999, ra:0, w:0, raa:0}
      ],
      [
        {count:0, r:220, angle:angle, ra:-12, w:0, raa:0.2},
        {count:10, r:999, angle:999, ra:0, w:0, raa:0}
      ]
  )
}






///////////////////////////////////////////////////////////
// after boss
// after boss
// after boss
// after boss
// after boss

// wave 1 after boss
bulletData[51].push([
	{ count:    0, r:  270, angle:    0, ra:   -5, w:    0, raa:    0, offset_r: 0, offset_t: 0 },
	{ count:   35, r:    0, angle:  999, ra:    0, w:    0, raa:    0, offset_r: 0, offset_t: 0 },
	{ count:   60, r:   90, aiming:  true, ra:    0, w:    0, raa:    0, offset_r: 0, offset_t: 0 }
]);
bulletData[52].push([
    { count:    0, r:  270, angle:  -10, ra:   -5.5, w:  0.3, raa:    0, offset_r: 0, offset_t: 0 },
    { count:   35, r:    0, angle:  999, ra:      0, w:    0, raa:    0, offset_r: 0, offset_t: 0 },
	{ count:   60, r:   90, aiming:  true, ra:    0, w:    0, raa:    0, offset_r: 0, offset_t: 0 }
]);
bulletData[52].push([
    { count:    0, r:  270, angle:   10, ra:   -5.5, w: -0.3, raa:    0, offset_r: 0, offset_t: 0 },
    { count:   35, r:    0, angle:  999, ra:      0, w:    0, raa:    0, offset_r: 0, offset_t: 0 },
	{ count:   60, r:   90, aiming:  true, ra:    0, w:    0, raa:    0, offset_r: 0, offset_t: 0 }
]);
for(let i = 0; i < 3; i++){
	bulletData[53].push([
		{ count:    0, r:  270, angle:  -20 + 20 * i, ra:   -6, w:  0.6 - 0.6 * i, raa:    0, offset_r: 0, offset_t: 0 },
    	{ count:   35, r:    0, angle:           999, ra:    0, w:              0, raa:    0, offset_r: 0, offset_t: 0 },
		{ count:   60, r:   90, aiming:         true, ra:    0, w:              0, raa:    0, offset_r: 0, offset_t: 0 }
	]);
}
for(let i = 0; i < 4; i++){
	bulletData[54].push([
		{ count:    0, r:  270, angle:  -30 + 20 * i, ra: -6.5, w:  0.9 - 0.6 * i, raa:    0, offset_r: 0, offset_t: 0 },
    	{ count:   35, r:    0, angle:           999, ra:    0, w:              0, raa:    0, offset_r: 0, offset_t: 0 },
		{ count:   60, r:   90, aiming:         true, ra:    0, w:              0, raa:    0, offset_r: 0, offset_t: 0 }
	]);
}
for(let i = 0; i < 5; i++){
	bulletData[55].push([
		{ count:    0, r:  270, angle:  -40 + 20 * i, ra:   -7, w:  1.2 - 0.6 * i, raa:    0, offset_r: 0, offset_t: 0 },
    	{ count:   35, r:    0, angle:           999, ra:    0, w:              0, raa:    0, offset_r: 0, offset_t: 0 },
		{ count:   60, r:   90, aiming:         true, ra:    0, w:              0, raa:    0, offset_r: 0, offset_t: 0 }
	]);
}

// wave 2 after boss
for(let i = 0; i < 18; i++){
  bulletData[56].push([
  	{ count:    0, r:  400, angle:      20 * i, ra:  -12, w:    0, raa:  0.2 },
    { count:   50, r:  999, angle:         999, ra:    0, w:    0, raa:    0 }
  ]);
  bulletData[56].push([
  	{ count:    0, r:  403, angle:  20 * i + 2, ra:  -12, w:    0, raa:  0.2 },
    { count:   50, r:  999, angle:         999, ra:    0, w:    0, raa:    0 }
  ]);
  bulletData[56].push([
  	{ count:    0, r:  409, angle:  20 * i + 4, ra:  -12, w:    0, raa:  0.2 },
    { count:   50, r:  999, angle:         999, ra:    0, w:    0, raa:    0 }
  ]);
  bulletData[56].push([
  	{ count:    0, r:  418, angle:  20 * i + 6, ra:  -12, w:    0, raa:  0.2 },
    { count:   50, r:  999, angle:         999, ra:    0, w:    0, raa:    0 }
  ]);
  bulletData[56].push([
  	{ count:    0, r:  430, angle:  20 * i + 8, ra:  -12, w:    0, raa:  0.2 },
    { count:   50, r:  999, angle:         999, ra:    0, w:    0, raa:    0 }
  ]);
  bulletData[56].push([
  	{ count:    0, r:  445, angle:  20 * i + 10, ra:  -12, w:    0, raa:  0.2 },
    { count:   50, r:  999, angle:          999, ra:    0, w:    0, raa:    0 }
  ]);
  bulletData[56].push([
  	{ count:    0, r:  463, angle:  20 * i + 12, ra:  -12, w:    0, raa:  0.2 },
    { count:   50, r:  999, angle:          999, ra:    0, w:    0, raa:    0 }
  ]);

  bulletData[56].push([
  	{ count:    0, r:  400, angle:      20 * i, ra:  -12, w:    0, raa:  0.2 },
    { count:   50, r:  999, angle:         999, ra:    0, w:    0, raa:    0 }
  ]);
  bulletData[56].push([
  	{ count:    0, r:  403, angle:  20 * i - 2, ra:  -12, w:    0, raa:  0.2 },
    { count:   50, r:  999, angle:         999, ra:    0, w:    0, raa:    0 }
  ]);
  bulletData[56].push([
  	{ count:    0, r:  409, angle:  20 * i - 4, ra:  -12, w:    0, raa:  0.2 },
    { count:   50, r:  999, angle:         999, ra:    0, w:    0, raa:    0 }
  ]);
  bulletData[56].push([
  	{ count:    0, r:  418, angle:  20 * i - 6, ra:  -12, w:    0, raa:  0.2 },
    { count:   50, r:  999, angle:         999, ra:    0, w:    0, raa:    0 }
  ]);
  bulletData[56].push([
  	{ count:    0, r:  430, angle:  20 * i - 8, ra:  -12, w:    0, raa:  0.2 },
    { count:   50, r:  999, angle:         999, ra:    0, w:    0, raa:    0 }
  ]);
  bulletData[56].push([
  	{ count:    0, r:  445, angle:  20 * i - 10, ra:  -12, w:    0, raa:  0.2 },
    { count:   50, r:  999, angle:          999, ra:    0, w:    0, raa:    0 }
  ]);
  bulletData[56].push([
  	{ count:    0, r:  463, angle:  20 * i - 12, ra:  -12, w:    0, raa:  0.2 },
    { count:   50, r:  999, angle:          999, ra:    0, w:    0, raa:    0 }
  ]);
}
for(let i = 0; i < 18; i++){
  bulletData[57].push([
  	{ count:    0, r:  360, angle:       20 * i, ra:  -11, w:    0, raa:  0.2 },
    { count:   40, r:  999, angle:          999, ra:    0, w:    0, raa:    0 }
  ]);
  bulletData[57].push([
  	{ count:    0, r:  370, angle:   20 * i + 2, ra:  -11, w:    0, raa:  0.2 },
    { count:   40, r:  999, angle:          999, ra:    0, w:    0, raa:    0 }
  ]);
  bulletData[57].push([
  	{ count:    0, r:  380, angle:   20 * i + 4, ra:  -11, w:    0, raa:  0.2 },
    { count:   40, r:  999, angle:          999, ra:    0, w:    0, raa:    0 }
  ]);
  bulletData[57].push([
  	{ count:    0, r:  387, angle:   20 * i + 6, ra:  -11, w:    0, raa:  0.2 },
    { count:   40, r:  999, angle:          999, ra:    0, w:    0, raa:    0 }
  ]);
  bulletData[57].push([
  	{ count:    0, r:  394, angle:   20 * i + 8, ra:  -11, w:    0, raa:  0.2 },
    { count:   40, r:  999, angle:          999, ra:    0, w:    0, raa:    0 }
  ]);
  bulletData[57].push([
  	{ count:    0, r:  400, angle:  20 * i + 10, ra:  -11, w:    0, raa:  0.2 },
    { count:   40, r:  999, angle:          999, ra:    0, w:    0, raa:    0 }
  ]);
  bulletData[57].push([
  	{ count:    0, r:  406, angle:  20 * i + 12, ra:  -11, w:    0, raa:  0.2 },
    { count:   40, r:  999, angle:          999, ra:    0, w:    0, raa:    0 }
  ]);
}

// wave 3 after boss
bulletData[58].push([
	{ count:    0, r:  260, angle:    0, random: 20, ra:   -7, w:  0, raa:  0.1, offset_r: 0, offset_t: 0 },
	{ count:   40, r:  999, angle:  999, random: 20, ra:    0, w:  0, raa:    0, offset_r: 0, offset_t: 0 }
]);
bulletData[58].push([
	{ count:    0, r:  265, angle:    0, random: 20, ra:   -7, w:  0, raa:  0.1, offset_r: 0, offset_t: 0 },
	{ count:   40, r:  999, angle:  999, random: 20, ra:    0, w:  0, raa:    0, offset_r: 0, offset_t: 0 }
]);
bulletData[58].push([
	{ count:    0, r:  270, angle:    0, random: 20, ra:   -7, w:  0, raa:  0.1, offset_r: 0, offset_t: 0 },
	{ count:   40, r:  999, angle:  999, random: 20, ra:    0, w:  0, raa:    0, offset_r: 0, offset_t: 0 }
]);
bulletData[58].push([
	{ count:    0, r:  275, angle:    0, random: 20, ra:   -7, w:  0, raa:  0.1, offset_r: 0, offset_t: 0 },
	{ count:   40, r:  999, angle:  999, random: 20, ra:    0, w:  0, raa:    0, offset_r: 0, offset_t: 0 }
]);
bulletData[58].push([
	{ count:    0, r:  280, angle:    0, random: 20, ra:   -7, w:  0, raa:  0.1, offset_r: 0, offset_t: 0 },
	{ count:   40, r:  999, angle:  999, random: 20, ra:    0, w:  0, raa:    0, offset_r: 0, offset_t: 0 }
]);


console.log(JSON.stringify(bulletData, null, 0));

var t = document.createElement("textarea");
t.value = JSON.stringify(bulletData, null, 0);
document.body.appendChild(t);
t.select();
document.execCommand("copy");
document.body.removeChild(t);


// JSON.stringify(bulletData, null, 2);
