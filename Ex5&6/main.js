const { match } = require('assert');
const fs = require('fs')

let filename = "data/data.txt"
var d;
fs.readFile(filename, 'utf8', (err, data) => {
    if(err){}

    // console.log(data)
    // console.log(scan_all(data));
    console.log(calculate(scan_all(data)));
});

function calculate(matches)
{
    console.log(matches)

    var sum = 0;
    for(var i = 0; i < matches.length; i++)
    {
        var x = matches[i].match(/(\d+)/g)
        
        sum += x[0] * x[1]
    }

    return sum;
}

function scan_all(string)
{
    var dontstarts = string.split('don\'t\(\)')

    var realstring = dontstarts[0];
    for(var i = 1; i < dontstarts.length; i++)
    {
        console.log(dontstarts[i])
        var dos = dontstarts[i].split('do\(\)')
        dos.shift()
        console.log(dos)
        realstring += dos.join('')
    }

    let pattern = /mul\((\d+),(\d+)\)/gm

    return realstring.match(pattern)
}