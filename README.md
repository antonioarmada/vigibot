# Vigibot

### ¿De qué estás habland Willis?

Hice una especie de Vigía para controlar el motor diesel (Maxion 2.5) de mi Land Rover Discovery 1 TDI (1997). Pero podría servir para cualquier motor que no traiga una ECU que ya lo haga.  Intente hacerlo lo más simple y barato posible para que sea fácil replicarlo y que no duela el bolsillo, pero a la vez que tenga características que el Vigía carece. Otra premisa general fue no intervenir ningun elemento original (agujerear, roscar, pegar, etc), de manera que sea todo revertible con solo extraer lo agregado. 


### Cosas que hace Vigibot:


* Tiene una pequeña pantalla que muestra valores en dígitos y barras. Yo la puse en el tablero sin modificar nada y prácticamente no obstruye la visión de otro instrumento.
* Mide temperatura en tapa de cilindro (Sonda digital de temp. Ds18b20 "sumergible").
* Mide temperatura de líquido refrigerante. (Use el bulbo original SIEMENS VDO AMR1425, desconectado el cable del tablero que pa' lo que funciona mejor nada)
* Mide presión de aceite (Con el bulbo de presión genérico de Orland Rober para instrumentos eléctricos)
* Mide voltaje en batería.
* Detecta que haya líquido refrigerante en el vaso de expansión.
* Tiene un buzzer que emite alarma intermitente cuando se acerca a los límites prefijados y un pitido inaguantable cuando se alcanza el límite. No hice corte de motor porque me pareció que trae más problemas que ventajas, si no frenas con el pitido del Vigibot mereces fundir el motor, así es y no hay más.


### Como lo podes replicar

En este [__LINK__](https://drive.google.com/drive/folders/1cZq4Y_eshzZ9uuhtVDmg_z0Mdc7BVrJg?usp=sharing) hay una carpeta donde vas a encontrar un pdf con fotos, diagramas electrónicos, tambíen planillas de cómo saqué los cálculos para que las mediciones sean precisas. Yo armé todo el controlador en una placa pre-agujereada porque me apuraba un viaje en la camioneta y no podía esperar un PCB descente. Si alguien se copa en replicarlo por ahí armamos el PCB, mientras solo vas a encontrar diagramas semánticos. El controlador es un Arduino Nano y en este repositorio está el código para cargarle.

Claro que todo esto no es un tutorial, solo intente organizar más o menos toda la info como para que alguien interesado en replicarlo (como mi Yo en el futuro) tenga una buen comienzo con varias cuestiones masticadas que me llevaron un tiempo resolver/encontrar. Entonces esto sería una especie de agradecimiento a los que compartieron la info que me permitió llegar a esto.


### ¿Queres que te haga uno yo y te lo cobre?

Escribime a antonioarmada@gmail.com. 

### Dudas y mejoras.

Si me escribis un email como este __"quiero hacerlo pero no entiendo tal cosa"__ no creo que conteste, [__la info__](https://drive.google.com/drive/folders/1cZq4Y_eshzZ9uuhtVDmg_z0Mdc7BVrJg?usp=sharing) esta toda comentada y completa como para ser entendida con un poquito de ganas. 

Si tenés sugerencias de mejoras encantado las leo agradecido e intento sumarlas al proyecto. La aclaración al pie, es que intenté mantener el código legible por humanos comunes y silvestres que no piensen en bits.. ¿Podría ser optimizado? Si claro, pero no quiero incluir cambios que no corrigen bugs, mejoren precisión o sumen funciones, así que poéticas de código o masturbaciones en C++ no serán incluidas. 

