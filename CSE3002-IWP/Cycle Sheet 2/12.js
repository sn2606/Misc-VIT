$(".blue").css({
    "font-weight" : "bold",
    "color" : "blue"
});

$("#change-btn").click(function(){
    var clr = $("#color").val();
    $(".blue").html(clr);
    $(".blue").css("color", clr.toLowerCase());
});