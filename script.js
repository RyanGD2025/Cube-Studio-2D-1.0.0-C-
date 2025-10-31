let engineRunning = false;

function startEngine() {
  if (!engineRunning) {
    document.getElementById('engine-status').textContent = 'Rodando';
    engineRunning = true;
    console.log('Engine iniciada');
  }
}

function stopEngine() {
  if (engineRunning) {
    document.getElementById('engine-status').textContent = 'Parado';
    engineRunning = false;
    console.log('Engine parada');
  }
}
