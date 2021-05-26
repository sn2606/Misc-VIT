var words = ["hello leloh", "coffee efocef", "bottle tletob", "cat tca", "sanitizer sniizreta", "medicine edeciimn"];
var k = 0;
var scrambled;
var unscrambled;
var w = document.querySelector("p#word");
console.log(w);

function putWord(){
    k = Math.floor(Math.random() * (words.length-1));
    console.log(k);
    var q = words[k].split(" ")
    unscrambled = q[0];
    scrambled = q[1];
    console.log(scrambled);
    w.innerHTML = scrambled;
    w.style.color = "red";
}

putWord();

document.getElementById("check-btn").onclick = function(){
    var guess = document.getElementById("answer").value;
    if(guess == unscrambled){
        alert("Success!");
    }else{
        alert("Failure");
    }

    location.reload();
    putWord();
}