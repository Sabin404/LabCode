library ieee;
use ieee.std_logic_1164.all;

entity ha_tb is
end ha_tb;

architecture test of ha_tb is
	component ha
		port(
			a: in std_ulogic;
			b: in std_ulogic;
			cout: out std_ulogic;
			s: out std_ulogic
		);
	end component;
	
	signal ain, bin, cout, sum : std_logic;

	begin
		half_adder: ha port map (a => ain, b => bin, cout => cout, s => sum);

		process begin

			ain <= '0';
			bin <= '0';
			wait for 1 ns;

			ain <= '0';
			bin <= '1';
			
			wait for 1 ns;

			ain <= '1';
			bin <= '0';
			
			wait for 1 ns;

			ain <= '1';
			bin <= '1';
			
			wait for 1 ns;

			

			assert false report "Congratulations bhaii ";
			wait;
		end process;
end test;
