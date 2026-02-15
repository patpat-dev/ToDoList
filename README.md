# Progetto C++: To Do List

Il progetto permette di rappresentare un elenco delle attività da svolgere, con possibilità di aggiungere, modificare e cancellare elementi salvati.

## Struttura del progetto
- `src/`: Contiene i file header (.h) e sorgenti (.cpp) delle classi `Task`, `ToDoList` e `MemoryManager`.
- `tests/`: Contiene i test unitari (`test_main.cpp`).
- `data/`: Directory del file `tasks.csv` destinato a salvare l'elenco delle attività.

### Caratteristiche principali:
- Aggiunta, visualizzazione dei dettagli, modifica e rimozione dei task.
- Salvataggio e caricamento dei dati da file `data/tasks.csv` in formato testuale.
- Gestione degli errori di input (validazione degli interi) e dei casi limite (indici fuori range).

## Note Tecniche
- Unit Testing: GoogleTest
- Per il versionamento è stato utilizzato **Git/GitHub** con per tracciare l'evoluzione dello sviluppo.