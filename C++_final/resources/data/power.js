// power[power_level][one_z shoting bullet {}, {}, {}....]
// offset_x : x margin
// offset_y : y margin
let front = -30;
let side = 50;
var power = [
    [
        [
            {"genre": 0, "color": 0, "bullet": 0, "angle": 180, "offset_x": 0, "offset_y": front}
        ],
        [
            {"genre": 0, "color": 0, "bullet": 0, "angle": 178, "offset_x": 0, "offset_y": front},
            {"genre": 0, "color": 0, "bullet": 0, "angle": 180, "offset_x": 0, "offset_y": front},
            {"genre": 0, "color": 0, "bullet": 0, "angle": 182, "offset_x": 0, "offset_y": front}
        ],
        [
            {"genre": 0, "color": 0, "bullet": 0, "angle": 176, "offset_x": 0, "offset_y": front},
            {"genre": 0, "color": 0, "bullet": 0, "angle": 178, "offset_x": 0, "offset_y": front},
            {"genre": 0, "color": 0, "bullet": 0, "angle": 180, "offset_x": 0, "offset_y": front},
            {"genre": 0, "color": 0, "bullet": 0, "angle": 182, "offset_x": 0, "offset_y": front},
            {"genre": 0, "color": 0, "bullet": 0, "angle": 184, "offset_x": 0, "offset_y": front}
        ]
    ],
    [
        [
            {"genre": 0, "color": 0, "bullet": 0, "angle": 180, "offset_x": 0, "offset_y": front}
        ],
        [
            {"genre": 0, "color": 0, "bullet": 0, "angle": 178, "offset_x": 0, "offset_y": front},
            {"genre": 0, "color": 0, "bullet": 0, "angle": 180, "offset_x": 0, "offset_y": front},
            {"genre": 0, "color": 0, "bullet": 0, "angle": 182, "offset_x": 0, "offset_y": front}
        ],
        [
            {"genre": 0, "color": 0, "bullet": 0, "angle": 176, "offset_x": 0, "offset_y": front},
            {"genre": 0, "color": 0, "bullet": 0, "angle": 178, "offset_x": 0, "offset_y": front},
            {"genre": 0, "color": 0, "bullet": 0, "angle": 180, "offset_x": 0, "offset_y": front},
            {"genre": 0, "color": 0, "bullet": 0, "angle": 182, "offset_x": 0, "offset_y": front},
            {"genre": 0, "color": 0, "bullet": 0, "angle": 184, "offset_x": 0, "offset_y": front}
        ]
    ]
];


console.log(JSON.stringify(power, null, 0));

var t = document.createElement("textarea");
t.value = JSON.stringify(power, null, 0);
document.body.appendChild(t);
t.select();
document.execCommand("copy");
document.body.removeChild(t);
