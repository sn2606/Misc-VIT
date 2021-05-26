var url;

function changeImage(input) {
    if (input.files && input.files[0]) {
        var reader = new FileReader();
        reader.onload = function (e) {
            var gimg = document.getElementById("greet-img");
            gimg.src = e.target.result;
            url = "url('" + gimg.src + "')";
            console.log(gimg.src);
            gimg.style.width = "500px";
            gimg.style.height = "500px";
        };
        reader.readAsDataURL(input.files[0]);
    }
}

var alignment = document.querySelectorAll('input[name="alignment"]');
var fontStyle = document.getElementById("font-style");
var fontSize = document.getElementById("font-size");
var fontColor = document.getElementById("font-color");
var text = document.querySelectorAll("#greeting-text p");
var textbox1 = document.getElementById("heading-text");
var textbox2 = document.getElementById("greet-text");
var textbox3 = document.getElementById("signature-text");
// var p1 = document.getElementById("heading");
// var p2 = document

function changeImageAlignment() {
    var gc = document.getElementById("greeting-card");
    var im = document.getElementById("greet-img");
    var imgDiv = document.getElementById("image");
    url = "url('" + im.src + "')";
    for (var i = 0; i < alignment.length; i++) {
        if (alignment[i].checked) {
            console.log(alignment[i]);
            if (alignment[i].id === "left-align") {
                imgDiv.style.display = "flex";
                gc.style.backgroundImage = "None";
                gc.style.flexDirection = "row-reverse";
                im.style.borderBottomLeftRadius = "10px";
                im.style.borderBottomRightRadius = "0px";
                im.style.borderTopLeftRadius = "10px";
                im.style.borderTopRightRadius = "0px";
                im.style.width = "500px";
                im.style.height = "500px";
            } else if (alignment[i].id === "right-align") {
                imgDiv.style.display = "flex";
                gc.style.backgroundImage = "None";
                gc.style.flexDirection = "row";
                im.style.borderBottomLeftRadius = "0px";
                im.style.borderBottomRightRadius = "10px";
                im.style.borderTopLeftRadius = "0px";
                im.style.borderTopRightRadius = "10px";
                im.style.width = "500px";
                im.style.height = "500px";
            } else if (alignment[i].id === "background") {

                imgDiv.style.display = "None";
                gc.style.backgroundImage = url;
            }
        }
    }
}

function changeFontStyle() {
    var family = fontStyle[fontStyle.selectedIndex].value;
    console.log(family);
    text.forEach((x) => {
        x.style.fontFamily = family;
    })
}

function changeFontSize() {
    var size = fontSize[fontSize.selectedIndex].value;
    text.forEach((x) => {
        x.style.fontSize = size + "px";
    })
}

function changeFontColor() {
    var color = fontColor[fontColor.selectedIndex].value;
    text.forEach((x) => {
        x.style.color = color;
    })
}

for (var i = 0; i < alignment.length; i++) {
    alignment[i].addEventListener("change", changeImageAlignment);
}

fontStyle.addEventListener("change", changeFontStyle);
fontSize.addEventListener("change", changeFontSize);
fontColor.addEventListener("change", changeFontColor);

document.getElementById("change1").addEventListener("click", function () {
    if (textbox1.value == "") {
        text[0].innerHTML = "Sincere Greetings";
    } else {
        text[0].innerHTML = textbox1.value;
    }
})

document.getElementById("change2").addEventListener("click", function () {
    if (textbox2.value == "") {
        text[1].innerHTML = "Hello, World!";
    } else {
        text[1].innerHTML = textbox2.value;
    }
})

document.getElementById("change3").addEventListener("click", function () {
    if (textbox3.value == "") {
        text[2].innerHTML = "From Y/N";
    } else {
        text[2].innerHTML = textbox3.value;
    }
})