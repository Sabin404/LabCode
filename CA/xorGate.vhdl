
library ieee;
use ieee.std_logic_1164.all;
entity xorGate is 
port(
a,b : in std_logic;
c: out std_logic
);
end xorGate;
architecture behaviour of xoGate is 
begin
c<= a XOR b;
end behaviour;
