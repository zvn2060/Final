var bulletData = 
[
  // 0: ???
  [
  	[
  	  { count:    0, r:  370, angle:    0, ra:  -12, w:    0, raa:  0.2 },
  	  { count:   50, r:  999, toPlayer: 1, ra:    0, w:    0, raa:    0 }
  	],
  	[
  	  { count:    0, r:  370, angle:   10, ra:  -12, w:    1, raa:  0.2 },
  	  { count:   50, r:  999, angle:  999, ra:    0, w:    0, raa:    0 }
  	],
  	[
  	  { count:    0, r:  370, angle:   20, ra:  -12, w:    1, raa:  0.2 },
  	  { count:   50, r:  999, angle:  999, ra:    0, w:    0, raa:    0 }
  	],
  	[
  	  { count:    0, r:  370, angle:   30, ra:  -12, w:    1, raa:  0.2 },
  	  { count:   50, r:  999, angle:  999, ra:    0, w:    0, raa:    0 }
  	],
  	[
  	  { count:    0, r:  370, angle:   40, ra:  -12, w:    1, raa:  0.2 },
  	  { count:   50, r:  999, angle:  999, ra:    0, w:    0, raa:    0 }
  	],
  	[
  	  { count:    0, r:  370, angle:  -10, ra:  -12, w:   -1, raa:  0.2 },
  	  { count:   50, r:  999, angle:  999, ra:    0, w:    0, raa:    0 }
  	],
  	[
  	  { count:    0, r:  370, angle:  -20, ra:  -12, w:   -1, raa:  0.2 },
  	  { count:   50, r:  999, angle:  999, ra:    0, w:    0, raa:    0 }
  	],
  	[
  	  { count:    0, r:  370, angle:  -30, ra:  -12, w:   -1, raa:  0.2 },
  	  { count:   50, r:  999, angle:  999, ra:    0, w:    0, raa:    0 }
  	],
  	[
  	  { count:    0, r:  370, angle:  -40, ra:  -12, w:   -1, raa:  0.2 },
  	  { count:   50, r:  999, angle:  999, ra:    0, w:    0, raa:    0 }
  	]
  ],
  // 1: ???
  [
  	[
  	  { count:    0, r:  370, angle:    0, ra:  -12, w:    0, raa:  0.2 },
  	  { count:   50, r:  100, toPlayer: 1, ra:    0, w:    0, raa:    0 }
  	],
  	[
  	  { count:    0, r:  370, angle:   10, ra:  -12, w:    1, raa:  0.2 },
  	  { count:   50, r:  100, toPlayer: 1, ra:    0, w:    0, raa:    0 }
  	],
  	[
  	  { count:    0, r:  370, angle:   20, ra:  -12, w:    1, raa:  0.2 },
  	  { count:   50, r:  100, toPlayer: 1, ra:    0, w:    0, raa:    0 }
  	],
  	[
  	  { count:    0, r:  370, angle:   30, ra:  -12, w:    1, raa:  0.2 },
  	  { count:   50, r:  100, toPlayer: 1, ra:    0, w:    0, raa:    0 }
  	],
  	[
  	  { count:    0, r:  370, angle:   40, ra:  -12, w:    1, raa:  0.2 },
  	  { count:   50, r:  100, toPlayer: 1, ra:    0, w:    0, raa:    0 }
  	],
  	[
  	  { count:    0, r:  370, angle:  -10, ra:  -12, w:   -1, raa:  0.2 },
  	  { count:   50, r:  100, toPlayer: 1, ra:    0, w:    0, raa:    0 }
  	],
  	[
  	  { count:    0, r:  370, angle:  -20, ra:  -12, w:   -1, raa:  0.2 },
  	  { count:   50, r:  100, toPlayer: 1, ra:    0, w:    0, raa:    0 }
  	],
  	[
  	  { count:    0, r:  370, angle:  -30, ra:  -12, w:   -1, raa:  0.2 },
  	  { count:   50, r:  100, toPlayer: 1, ra:    0, w:    0, raa:    0 }
  	],
  	[
  	  { count:    0, r:  370, angle:  -40, ra:  -12, w:   -1, raa:  0.2 },
  	  { count:   50, r:  100, toPlayer: 1, ra:    0, w:    0, raa:    0 }
  	]
  ],
];

console.log(JSON.stringify(bulletData, null, 0));

var t = document.createElement("textarea");
t.value = JSON.stringify(bulletData, null, 2);
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