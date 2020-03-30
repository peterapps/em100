var vgaCanvas = false;
var vgaCtx = false;

function vgaInit(){
    vgaCanvas = document.getElementById("vga_canvas");
    vgaCtx = vgaCanvas.getContext("2d");
}