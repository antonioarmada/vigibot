# Vigibot

### ¿De qué estás habland Willis?

Hice un especie de Vigía para controlar el motor diesel (Maxion 2.5) de mi Land Rover Discovery 1 TDI (1997). Pero podria servir para cualquier motor que que no traiga una ECU que ya lo haga.  Intente hacerlo lo mas simple y barato posible para que sea fácil replicarlo y que no duela el bolsillo, pero a la vez que tenga características que el Vigía carece. Otra premisa general fue no intervenir (agujerear, roscar, pegar, etc), de manera que sea todo revertible con solo extraer los elementos. Cosas que hace Vigibot:

* Tiene una pequeña pantalla que muestra valores en dígitos y barras. Yo la puse en el tablero sin modificar nada y practicamente no obstruye la visión de otro instrumento.
* Mide temperatura en tapa de cilindro (Sonda de temp. Ds18b20 "sumergible").
* Mide temperatura de líquido refigerante. (Use el bulbo original SIEMENS VDO AMR1425, deconectado el cable del tablero que pa' lo que funciona mejor nada)
* Mide presión de aceite (Con el bulbo de presión genérico de Orland Rober para instrumentos eléctricos)
* Mide voltaje en batería.
* Detecta que haya liquído regrigerante en el vaso de expansión.
* Tiene un buzzer que emite alarma cuando se acerca a los límites prefijados y un pitido inaguantable cuando se alcanza el limite. No hice corte de motor porque me parecio que trae mas problemas que ventajas, si no freno con el pitido del Vigibot merezco fundir el motor, asi es y no hay mas.

### Como lo podes replicar

En este [__LINK__](https://drive.google.com/drive/folders/1cZq4Y_eshzZ9uuhtVDmg_z0Mdc7BVrJg?usp=sharing) vas a encontrar una carpeta en drive con fotos, diagramas electrónicos y planillas de cómo saqué los cáluclos para que las mediciones sean precisas. Yo armé todo en una placa pre-perforada porque estaba apurado para hacer un PCB como debería. Si alguien se copa en replciarlo por ahi armamos PCB, mientras solo vas a encontrar diagramas semáticos. El controlador es un Arduino Nano y lo que está en este repositorio es el código para el controlador. La aclaración es que intenté mantener el código leigle por humanos comunes y silvestres que no piensen en bits.. ¿Podria ser optimizado? Si claro.

Claro que todo esto no es un tutorial, solo intente organizar mas o menos toda la info como para que alguien interesado en replicarlo (como mi yo en el futuro) tenga una buen comienzo con varias cuestiones masticadas que me llevaron un tiempo resolver/encontrar. Entonces esto seria una especie de agradecimeinto a los que compartieron la info que me permitió llegar a esto.


### ¿Queres que te haga uno yo y te lo cobre?

Escribime a antonioarmada@gmail.com. 

### Dudas y mejoras.

Si me escribis un email como este __"quiero hacerlo pero no entiendo tal cosa"__ no creo que conteste, [__la info__](https://drive.google.com/drive/folders/1cZq4Y_eshzZ9uuhtVDmg_z0Mdc7BVrJg?usp=sharing) esta toda comentada y completa como para ser entendida con un poquito de ganas. 

Si tenés sugerencias de mejoras encantado las leo agradecido e intento sumarlas al proyecto.


