library ieee;
use ieee.std_logic_1164.all;
entity nandGate is 
port(
a,b : in std_logic; 
c,d: out std_logic
);
end nandGate;
architecture behaviour of nandGate is 
begin
c<= a and b; 
d<= a nand b;
end behaviour;
