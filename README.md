# transmission-light

This is the indicator light that says whether you are rehearsing, transmitting or both.

The arduino is controlled by HTTP GET requests and is in the format \<IP address\>/?[request].

This can also be controlled from the desk push-buttons, see the controller section.

## GET requests

* Turn on rehearsal light - \<IP address\>/?rehearsal_on
* Turn on transmission light - \<IP address\>/?transmission_on
* Turn on both rehearsal and transmission light - \<IP address\>/?rehearsal_transmission_on
* Turn off both rehearsal  lights - \<IP address\>/?rehearsal_transmission_off

## Transmission light controller

See [transmission-light-controller](https://github.com/ystv/transmission-light-controller)

## Schematic

<img width="887" alt="Schematic" src="https://user-images.githubusercontent.com/20305872/142750597-83e6f535-9ca5-46f1-84dd-e6f781e2384e.png">
