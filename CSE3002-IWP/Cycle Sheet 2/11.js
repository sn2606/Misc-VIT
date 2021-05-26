$(function(){
    $("#head").css({
        "background-color":"#eee",
        "font-family" : "sans-serif"
    })

    $(".row:even").css({
        "background-color": "gray",
        "color": "white"
    })

    $("tr td:nth-child(1)").css({
        "width" : "120px",
    })

    $("tr td:nth-child(2)").css({
        "width" : "120px",
    })

    $("tr td:nth-child(3)").css({
        "width" : "200px",
    })

    $("tr td:nth-child(4)").css({
        "width" : "150px",
    })
});