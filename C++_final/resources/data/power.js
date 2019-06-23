// power[power_level][one_z shoting bullet {}, {}, {}....]
// offset_x : x margin
// offset_y : y margin
let front = -30;
let side = 50;
var power = [
    [],
    []
];

let bullet_num = [1, 3, 5, 9, 9, 11, 11, 11, 21];

for(let level = 0 ; level <= 8 ; level++){
    power[0].push([]);
    power[1].push([]);
    for(let bullet = 1 ; bullet <= bullet_num[level]; bullet++){
        let middle = Math.ceil(bullet_num[level] / 2);
        power[0][level].push(
            {genre: 0, color: 0, bullet: 0, angle: 180 + 5 * (bullet - middle), offset_x: 0, offset_y: front}
        );
        power[1][level].push(
            {genre: 0, color: 0, bullet: 0, angle: 180 + 2 * (bullet - middle), offset_x: 0, offset_y: front}
        );
    }
}


console.log(JSON.stringify(power, null, 0));

var t = document.createElement("textarea");
t.value = JSON.stringify(power, null, 0);
document.body.appendChild(t);
t.select();
document.execCommand("copy");
document.body.removeChild(t);
