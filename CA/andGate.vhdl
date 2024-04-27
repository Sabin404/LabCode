To create a VHDL file for implementing AND logic.
Source Code: 
library ieee;
use ieee.std_logic_1164.all;
entity andGate is
 port(
 a,b : in std_logic;
 c: out std_logic
 );
end andGate;
architecture behaviour of andGate is
 begin 
 c<= a and b;
end behaviour