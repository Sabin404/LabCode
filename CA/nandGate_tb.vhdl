library ieee;
use ieee.std_logic_1164.all;
entity nandGate_tb is 
end nandGate_tb;
architecture test of nandGate_tb is 
component nandGate
port(
a,b : in std_logic; 
c,d : out std_logic
);
end component;
signal a,b,c,d : std_logic; 
begin
nandGate_inst: nandGate port map 
( a => a, b => b, c => c, d => d);
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
