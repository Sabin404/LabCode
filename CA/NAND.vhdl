
library ieee;
use ieee.std_logic_1164.all;
entity NAND is 
port(
a,b : in std_logic; 
c,d: out std_logic
);
end NAND;
architecture behaviour of NAND is 
begin
c<= a and b; 
d<= a nand b;
end behaviour;
