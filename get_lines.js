const fs = require("fs"),files = [
    "./main.cpp",
    "./run.h",
    "./main.h",
    "./head/calc.h",
    "./head/error.h",
    "./head/fs.h",
    "./head/keywI.h",
    "./head/mode_cli.h",
    "./head/req.h",
    "./head/rt.h",
    "./head/stdhead.h",
    "./head/str.h",
    "./head/trans.h",
    "./head/types.h",
    "./head/var.h",
];
var lines = 0;

console.log("filename    lines");

for(let i=0;i<files.length;++i) {
    let cont = fs.readFileSync(files[i],"utf-8"),c = cont.split("\n").length;
    lines += c;
    console.log(files[i],"   ",c);
}

console.log("total        ",lines);