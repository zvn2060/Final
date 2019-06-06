var bulletData = 
[
  // 0: ???
  [
  	[
  	  { count:    0, r:  370, angle:    0, ra:  -12, wa:  "r", raa:  0.2 },
  	  { count:   50, r:   20, angle:    0, ra:    0, wa:    0, raa:    0 }
  	],
  	[
  	  { count:    0, r:  370, angle:   10, ra:  -12, wa:    1, raa:  0.2 },
  	  { count:   50, r:   20, angle:   10, ra:    0, wa:    0, raa:    0 }
  	],
  	[
  	  { count:    0, r:  370, angle:  -10, ra:  -12, wa:   -1, raa:  0.2 },
  	  { count:   50, r:   20, angle:  -10, ra:    0, wa:    0, raa:    0 }
  	],
  	[
  	  { count:    0, r:  370, angle:   20, ra:  -12, wa:    1, raa:  0.2 },
  	  { count:   50, r:   20, angle:   20, ra:    0, wa:    0, raa:    0 }
  	],
  	[
  	  { count:    0, r:  370, angle:  -20, ra:  -12, wa:   -1, raa:  0.2 },
  	  { count:   50, r:   20, angle:  -20, ra:    0, wa:    0, raa:    0 }
  	],
  	[
  	  { count:    0, r:  370, angle:   30, ra:  -12, wa:    1, raa:  0.2 },
  	  { count:   50, r:   20, angle:   30, ra:    0, wa:    0, raa:    0 }
  	],
  	[
  	  { count:    0, r:  370, angle:  -30, ra:  -12, wa:   -1, raa:  0.2 },
  	  { count:   50, r:   20, angle:  -30, ra:    0, wa:    0, raa:    0 }
  	],
  	[
  	  { count:    0, r:  370, angle:   40, ra:  -12, wa:    1, raa:  0.2 },
  	  { count:   50, r:   20, angle:   40, ra:    0, wa:    0, raa:    0 }
  	],
  	[
  	  { count:    0, r:  370, angle:  -40, ra:  -12, wa:   -1, raa:  0.2 },
  	  { count:   50, r:   20, angle:  -40, ra:    0, wa:    0, raa:    0 }
  	]
  ],
  // 1: ???
  [

  ]
];

console.log(JSON.stringify(bulletData, null, 0));

var t = document.createElement("textarea");
t.value = JSON.stringify(bulletData, null, 2);
document.body.appendChild(t);
t.select();
document.execCommand("copy");
document.body.removeChild(t);


// JSON.stringify(bulletData, null, 0);

var c = 50;
var r_0 = 370;
var ra_0 = -12;
var raa = 0.2;
console.log(1/2*raa*Math.pow(c, 2) + ra_0*c);