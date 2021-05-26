const questions = [
    {
        Question: "What is the color of the sky?",
        Option1: "Blue",
        Option2: "Red",
        Option3: "Black",
        Option4: "Green"
    },
    {
        Question: "Which of the following does not have caffeine?",
        Option1: "Coffee",
        Option2: "Tea",
        Option3: "Red Bull",
        Option4: "Cotton"
    },
    {
        Question: "Wich of the following is a fruit?",
        Option1: "Cabbage",
        Option2: "Mango",
        Option3: "Cauliflower",
        Option4: "Potato"
    },
    {
        Question: "Which of the following has a red color?",
        Option1: "Water",
        Option2: "Leaf",
        Option3: "Soil",
        Option4: "Blood"
    },
    {
        Question: "Which of the following is not a Scandinivian country?",
        Option1: "Finland",
        Option2: "Norway",
        Option3: "New Zealand",
        Option4: "Denmark"
    },
];

var answers = [1, 4, 2, 4, 3];
var selected = [];

var questionCount = -1;
var q = document.getElementById("Question");
var op1 = document.getElementById("option1-text");
var op2 = document.getElementById("option2-text");
var op3 = document.getElementById("option3-text");
var op4 = document.getElementById("option4-text");
var optionBtn = document.querySelectorAll('input[name="option"]');
var nextBtn = document.getElementById("next-btn");

function displayResult() {
    var score = 0;

    for(var i = 0; i < selected.length; i++){
        if(selected[i]){
            if(parseInt(selected[i]) == answers[i]){
                score++;
            }
        }
    }

    document.getElementById("question-area").style.display = "None";
    document.getElementById("result").innerHTML = "Your score is " + score.toString();
}

function displayQuestion() {
    questionCount++;
    console.log(questionCount);
    console.log(selected);

    if(questionCount >= questions.length){
        displayResult();
    }else{

        window.setTimeout(displayQuestion, 30000);

        for(var i = 0; i < optionBtn.length; i++){
            optionBtn[i].checked = false;
        }

        q.innerHTML = questions[questionCount].Question;
        op1.innerHTML = questions[questionCount].Option1;
        op2.innerHTML = questions[questionCount].Option2;
        op3.innerHTML = questions[questionCount].Option3;
        op4.innerHTML = questions[questionCount].Option4;
    }
}

displayQuestion();

function updateSelected() {
    for(var i = 0; i < optionBtn.length; i++){
        if(optionBtn[i].checked){
            selected[questionCount] = (optionBtn[i].id);
            console.log(selected);
        }
    }
}

for(var i = 0; i < optionBtn.length; i++){
    optionBtn[i].addEventListener("change", updateSelected);
}

nextBtn.addEventListener("click", displayQuestion);