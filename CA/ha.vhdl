library ieee;
use ieee.std_logic_1164.all;

entity ha is
		port(
			a: in std_ulogic;
			b: in std_ulogic;
			cout: out std_ulogic;
			S:out std_ulogic
		);
end ha;

architecture behave of ha is
begin
	S<=(a xor b);
	cout<=(a and b);

end behave;