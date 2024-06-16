# Erogatore di bibite con autorizzazione RFID con stm32f-arduino 🚰
Progettazione di un distributore di bevande con autorizzazione NFC. trasmissione tra stm32f3Discovery e arduino uno. Progetto per l'esame CSD/APC.

Inserire foto finale...
## Indice
- [Erogatore di bibite con autorizzazione RFID con stm32f-arduino 🚰](#erogatore-di-bibite-con-autorizzazione-rfid-con-stm32f-arduino-)
  - [Indice](#indice)
  - [Introduzione](#introduzione)
  - [STM collegamento Uart ad Arduino](#stm-collegamento-uart-ad-arduino)
  - [Sensore RFID ed autorizzazione](#sensore-rfid-ed-autorizzazione)
  - [Licenza](#licenza)


## Introduzione
Il lavoro consiste nella progettazione e realizzazione di un erogatore di bevande.  
Per tale scopo sono stati utilizzati diversi dispositivi per testare le svariate tipologie di comunicazione affrontate durante il corso.

Come primo obiettivo del progetto abbiamo deciso di realizzare una comunicazione tra un Arduino Uno ed una scheda della ST Microelectronics (STM32F3DISCOVERY).  
La parte dell'autorizzazione all'erogazione è stata implementata in Arduino con un lettore RFID (comunicazione SPI).  
Tramite comunicazione seriale viene trasmesso l'ID della carta autorizzata all'erogazione.  
Tale ID viene mostrato su uno schermo con un adattatore $I^2C$ .  
Tramite un tastierino viene così inserita la quantità di fluido da erogare espressa in millilitri.  
Viene quindi attivata la pompa tramite un relè e quando il flussimetro rileva la quantità corretta viene interrotto il flusso spegnendo la pompa.

## STM collegamento Uart ad Arduino
![Uart](https://raw.githubusercontent.com/mgalateo/erogatore-bibite-nfc-stm32f-arduino/main/Documenti%20e%20Immagini/Immagini/UartArduinoStm.png?token=GHSAT0AAAAAACOE5JM7SJISZ6NZX6DY3PLYZTPBFXQ "Connessione STM-Arduino")

Per la comunicazione tra la scheda ST e Arduino, è stata scelta una comunicazione asincrona tramite UART. Sulla STM32F3Discovery, è stata utilizzata la UART4 con i pin PC10 come TX e PC11 come RX. Sulla scheda Arduino, tramite la libreria "SoftwareSerial", sono stati scelti i pin 7 per TX e 8 per RX.

Dopo vari test e ricerche, si è constatato che i pin della scheda ST utilizzano un livello logico a 3.3V, mentre quelli di Arduino utilizzano 5V. Pertanto, è stato aggiunto al circuito un convertitore di livello logico bidirezionale per adattare correttamente i segnali tra i pin, come mostrato in figura.

## Sensore RFID ed autorizzazione
![RFID](https://raw.githubusercontent.com/mgalateo/erogatore-bibite-nfc-stm32f-arduino/main/Documenti%20e%20Immagini/Immagini/RFID.jpg?token=GHSAT0AAAAAACOE5JM7BBPWM77CKMIW4MCQZTPCIHQ "CONNESSIONE CIRCUITO AUTORIZZAZIONE")

Per utilizzare il sensore RFID, è stata necessaria la comunicazione SPI, come mostrato nei collegamenti in figura. Se il tag RFID non è presente nella lista, si accenderà il LED rosso e il buzzer emetterà un suono di errore. Quando la scheda viene riconosciuta, l'ID letto viene comunicato alla scheda ST, il LED verde si accenderà e il buzzer emetterà un suono di conferma dell'accesso corretto.


## Licenza
Informazioni sulla licenza del progetto.


