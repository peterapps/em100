function handleRun(){
    if (comp.cpu.running){
        comp.cpu.running = false;
        return;
    }
    message("Running.");
    document.getElementById("run_btn").value = "Stop";
    requestAnimationFrame(cpuLoop);
}

function cpuLoop(){
    comp.cpu.executeOps(130);

    if (comp.cpu.running) requestAnimationFrame(cpuLoop);
    else {
        document.getElementById("run_btn").value = "Run";
        message("Halted.");
    }
}