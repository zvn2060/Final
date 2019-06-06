var bulletData = 
[
  // 0: ???
  [
  	[
  	  { count:    0, r:   15, angle:   10, ra:    0, wa:    1, raa:    0 },
  	  { count:   50, r:    0, angle:    0, ra:    0, wa:    0, raa:    0 }
  	],
  	[
  	  { count:    0, r:   15, angle:  -10, ra:    0, wa:   -1, raa:    0 },
  	  { count:   50, r:    0, angle:    0, ra:    0, wa:    0, raa:    0 }
  	],
  	[
  	  { count:    0, r:   15, angle:    0, ra:    0, wa:  "r", raa:    0 },
  	  { count:   50, r:    0, angle:    0, ra:    0, wa:    0, raa:    0 }
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