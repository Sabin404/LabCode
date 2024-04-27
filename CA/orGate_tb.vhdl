
library ieee;
use ieee.std_logic_1164.all;
entity orGate_tb is
 end orGate_tb;
architecture test of orGate_tb is 
 component orGate
 port(
 a,b : in std_logic;
 c: out std_logic
 ); 
 end component;
signal a,b,c : std_logic;
begin orGate_inst: orGate port map 
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
