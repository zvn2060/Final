var bulletData = 
[
  // 0: showcase
  [],
  // 1: showcase
  [],
  // 2: showcase
  []

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
  { count:   50, r:    0, angle:      0, ra:    0, w:    0, raa:    0 },
  { count:   60, r:  140, aiming:  true, ra:    0, w:    0, raa:    0 }
])
for(let i = 1; i <= 5; i++){
  bulletData[1].push([
    { count:    0, r:  360 - i*10, angle:  10 * i, ra:   -4, w:    0, raa:    0 },
    { count:   50, r:           0, angle:       0, ra:    0, w:    0, raa:    0 },
    { count:   60, r:         140, aiming:   true, ra:    0, w:    0, raa:    0 }
  ])
  bulletData[1].push([
    { count:    0, r:  360 - i*10, angle: -10 * i, ra:   -4, w:    0, raa:    0 },
    { count:   50, r:           0, angle:       0, ra:    0, w:    0, raa:    0 },
    { count:   60, r:         140, aiming:   true, ra:    0, w:    0, raa:    0 }
  ])
}

for(let i = 1; i <= 12; i++){
  bulletData[2].push([
    { count:    0, r:   30, angle:    0, ra:    1, w:    0, raa:    0, offset_r: 25, offset_t: 30*i },
    { count:   70, r:  999, angle:  999, ra:    0, w:    0, raa:    0, offset_r: 25, offset_t: 30*i }
  ])
}

console.log(JSON.stringify(bulletData, null, 0));

var t = document.createElement("textarea");
t.value = JSON.stringify(bulletData, null, 0);
document.body.appendChild(t);
t.select();
document.execCommand("copy");
document.body.removeChild(t);


// JSON.stringify(bulletData, null, 2);

var c = 50;
var r_0 = 370;
var ra_0 = -12;
var raa = 0.2;
console.log(1/2*raa*Math.pow(c, 2) + ra_0*c);