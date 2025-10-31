document.addEventListener('DOMContentLoaded', () => {
  // Navegação do Hub
  const buttons = document.querySelectorAll('#hub .nav-btn');
  const tabs = document.querySelectorAll('main section.tab');

  buttons.forEach(button => {
    button.addEventListener('click', () => {
      buttons.forEach(btn => btn.classList.remove('active'));
      button.classList.add('active');

      tabs.forEach(tab => {
        tab.classList.remove('active');
        if(tab.id === button.dataset.view) {
          tab.classList.add('active');
        }
      });
    });
  });

  // Controles do Editor
  const showExplorerBtn = document.getElementById('showExplorerBtn');
  const showPropertiesBtn = document.getElementById('showPropertiesBtn');
  const showOutputBtn = document.getElementById('showOutputBtn');

  const explorer = document.getElementById('explorer');
  const properties = document.getElementById('properties');
  const output = document.getElementById('output');

  showExplorerBtn.addEventListener('click', () => {
    toggleVisibility(explorer);
  });

  showPropertiesBtn.addEventListener('click', () => {
    toggleVisibility(properties);
  });

  showOutputBtn.addEventListener('click', () => {
    toggleVisibility(output);
  });

  function toggleVisibility(element) {
    if (element.style.display === 'block') {
      element.style.display = 'none';
    } else {
      element.style.display = 'block';
    }
  }

  // Abrir editor de scripts
  const openScriptEditorBtn = document.getElementById('openScriptEditorBtn');
  const scriptEditor = document.getElementById('scriptEditor');

  openScriptEditorBtn.addEventListener('click', () => {
    scriptEditor.focus();
    alert('Editor CSScript aberto - fonte Ubuntu Mono ativada.');
  });

  // Atalhos de teclado (Windows)
  document.addEventListener('keydown', (e) => {
    if (e.ctrlKey) {
      switch (e.key.toLowerCase()) {
        case 'd': // Ctrl + D para duplicar
          alert('Comando: Duplicar (Ctrl + D)');
          e.preventDefault();
          break;
        case 'g': // Ctrl + G para agrupar
          alert('Comando: Agrupar (Ctrl + G)');
          e.preventDefault();
          break;
        case 'f': // Ctrl + F para criar pasta
          alert('Comando: Criar Pasta (Ctrl + F)');
          e.preventDefault();
          break;
      }
    } else if (e.key === 'F11') { // Tela cheia
      toggleFullScreen();
      e.preventDefault();
    }
  });

  function toggleFullScreen() {
    if (!document.fullscreenElement) {
      document.documentElement.requestFullscreen();
    } else {
      if (document.exitFullscreen) {
        document.exitFullscreen();
      }
    }
  }
});
