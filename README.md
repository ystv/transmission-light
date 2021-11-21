# transmission-light
This is the indicator light that says whether you are rehearsing, transmitting or both.

The arduino is controlled by HTTP GET requests and is in the format \<IP address\>/?[request].

## GET requests

* Turn on rehearsal light - \<IP address\>/?rehearsal_on
* Turn on transmission light - \<IP address\>/?transmission_on
* Turn on both rehearsal and transmission light - \<IP address\>/?rehearsal_transmission_on
* Turn off both rehearsal  lights - \<IP address\>/?rehearsal_transmission_off

## Schematic

<img width="959" alt="Schematic" src="https://user-images.githubusercontent.com/20305872/142749979-c76595e6-6f84-4747-8471-53a6529790ec.png">
