library ieee;
use ieee.std_logic_1164.all;
entity notGate is
 port(
 a : in std_logic;
 b : out std_logic
);
end notGate;
architecture behaviour of notGate is
 begin 
 b <= not a;
end behaviour;