# Erogatore di bibite con autorizzazione RFID con stm32f-arduino 🚰
Progettazione di un distributore di bevande con autorizzazione NFC. trasmissione tra stm32f3Discovery e arduino uno. Progetto per l'esame CSD/APC.

Inserire foto finale...
## Indice
- [Erogatore di bibite con autorizzazione RFID con stm32f-arduino 🚰](#erogatore-di-bibite-con-autorizzazione-rfid-con-stm32f-arduino-)
  - [Indice](#indice)
  - [Introduzione](#introduzione)
  - [STM collegamento Uart ad Arduino](#stm-collegamento-uart-ad-arduino)
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


## Licenza
Informazioni sulla licenza del progetto.


