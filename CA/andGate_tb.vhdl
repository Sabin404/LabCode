To create a testbench for the AND logic VHDL file.
library ieee;
use ieee.std_logic_1164.all;
entity andGate_tb is
 end andGate_tb;
architecture test of andGate_tb is 
 component andGate
 port(
 a,b : in std_logic;
 c: out std_logic
 ); 
 end component;
signal a,b,c : std_logic;
 begin
 andGate_inst: andGate port map 
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