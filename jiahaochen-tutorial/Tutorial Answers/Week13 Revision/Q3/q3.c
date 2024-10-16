x: def

y: def

z: def

w: dec

dec, def
dec, def


static: acessible only in the file which dec the var / function <- Internal Linkage

everything else: External Linkage

• A variable or function has internal linkage if it is defined in the current translation unit.
• A variable or function has external linkage if it is defined in another translation unit.
• Any variable or function that is declared static has internal linkage, it is good practice to declare
every variable or function as static unless it needs to be accessible from another translation uni