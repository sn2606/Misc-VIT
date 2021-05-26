document.getElementById("register").onclick = function () {
    var form = document.getElementById("q2");
    var fn = document.getElementById("full-name");
    var email = document.getElementById("email");
    var pwd = document.getElementById("pwd");
    var dob = document.getElementById("dob");
    var cnt = document.getElementById("country");
    var gender = document.querySelectorAll('input[name="gender"]');
    var meal1 = document.getElementById("low-cal");
    var meal2 = document.getElementById("low-salt");
    var terms = document.getElementById("terms");

    var total = 0;
    var reg = /^[A_Z][a-z]*,\s[A_Z][a-z]*$/
    if (!(fn.value.match(reg))) {
        document.getElementById("fn-inc").innerHTML += ": PLEASE ENTER IN CORRECT FORMAT";
        total = 1;
    }

    reg = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    console.log(email.value);
    console.log(email.value.match(reg));
    if (!(email.value.match(reg))) {
        document.getElementById("em-inc").innerHTML += ": PLEASE ENTER IN CORRECT FORMAT";
        total = 1;
    }

    reg = /[A-Za-z0-9@!]/
    if (!pwd.value.match(reg)) {
        document.getElementById("em-inc").innerHTML += ": PLEASE ENTER IN CORRECT FORMAT";
        total = 1;
    }

    reg = /^\d{1,2}\/\d{1,2}\/\d{4}$/;
    if (!dob.value.match(reg)) {
        document.getElementById("dob-inc").innerHTML += ": PLEASE ENTER IN CORRECT FORMAT";
        total = 1;
    }

    reg = /^[A-Z]/;
    if (!cnt.value.match(reg)) {
        document.getElementById("cnt-inc").innerHTML += ": PLEASE ENTER IN CORRECT FORMAT";
        total = 1;
    }

    var flag = 0;
    for (var i = 0; i < gender.length; i++) {
        if (gender[i].checked)
            flag = 1;
    }
    if (flag === 0) {
        document.getElementById("gen-inc").innerHTML += ": PLEASE CHECK SOMETHING";
        total = 1;
    }

    flag = 0;
    if (meal1.checked || meal2.checked)
        flag = 1;

    if (flag === 0) {
        document.getElementById("meal-pref").innerHTML += ": PLEASE CHECK SOMETHING";
        total = 1;
    }

    if (!terms.checked) {
        document.getElementById("terms-inc").innerHTML += ": PLEASE CHECK SOMETHING";
        total = 1;
    }

    // if (total) {
    //     form.reset();
    // }

}