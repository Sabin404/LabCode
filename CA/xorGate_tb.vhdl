
library ieee;
use ieee.std_logic_1164.all;
entity xorGate_tb is 
end xorGate_tb;
architecture test of xorGate_tb is 
component xorGate
port(
a,b : in std_logic; 
c : out std_logic
);
end component;
signal a,b,c : std_logic; 
begin
xorGate_inst: xorGate port map 
( a => a, b => b, c => c);
process begin
a <= '0';
b <= '0';
wait for 1 ns;
a <= '0';
b <= '1';
wait for 1 ns;
a <= '1';
b <= '0';
wait for 1 ns; 
a <= '1';
b <= '1';
wait for 1 ns;
assert false report "successfully completed"; 
wait;
end process; 
end test;
