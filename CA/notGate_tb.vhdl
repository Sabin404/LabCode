library ieee;
use ieee.std_logic_1164.all;
entity notGate_tb is
 end notGate_tb;
architecture test of notGate_tb is 
 component notGate
 port(
 a: in std_logic;
 b: out std_logic
 ); 
 end component;
signal a, b : std_logic;
begin
 notGate_inst: notGate port map 
 ( a => a, b => b );
 process begin
 a <= '0';
 wait for 1 ns;
 a <= '1';
 wait for 1 ns;
 assert false report "successfully completed";
 wait;
 end process;
end test;