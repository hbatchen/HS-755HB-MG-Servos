# HS-755HB-MG-Servos

Slightly different to standard model servos due to extended rotation range.

1) Controlling with buttons / joystic switch
   Using switches the servos stop when switches are released or joystick returns 
   to centre, rather than carrying on moving. 
   The ground is disconnected (via mosfet) in software when no button pressed.
   Also the signal pins are written low because the servos ticked 
   a bit with just ground disconnected.

2) Controlling with pots / joystic pots 
   I'll probably upload some code for this later
