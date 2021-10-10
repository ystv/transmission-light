# transmission-light
This is the indicator light that says whether you are rehearsing, transmitting or both.

The arduino is controlled by HTTP GET requests and is in the format \<IP address\>/?[request].

## GET requests

* Turn on rehearsal light - \<IP address\>/?rehearsal_on
* Turn on transmission light - \<IP address\>/?transmission_on
* Turn on both rehearsal and transmission light - \<IP address\>/?rehearsal_transmission_on
* Turn off both rehearsal  lights - \<IP address\>/?rehearsal_transmission_off

## Schematic

<img width="896" alt="Screenshot 2021-10-10 at 02 17 14" src="https://user-images.githubusercontent.com/20305872/136677863-42257012-78b3-4ee7-ad19-89c386df21c7.png">
