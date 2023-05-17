library IEEE;
use IEEE.std_logic_1164.all;

entity mux_tb is
end mux_tb;

architecture tb of mux_tb is
component mux_4x1 with is
  port(
    x0,x1,x2,x3: in std_logic;
    sel: in std_logic_vector(1 downto 0);
    z: out std_logic;
  );
end component;

signal x0,x1,x2,x3, z: std_logic;
signal sel: in std_logic_vector(1 downto 0);



begin

duv:mux_4x1 port map(
  x0 => x0,
  x1 => x1,
  x2 => x2,
  x3 => x3,
  sel => sel,
  z => z
);

drv: process begin
  x0 <= '1';
  x1 <= 'Z'; //resistência infinita
  x2 <= 'X'; //valor indefinido
  x3 <= '0';

  sel <= "00"; //binario
  wait for 1 ns;

  sel <= "01"; //binario
  wait for 1 ns;

  sel <= "10"; //binario
  wait for 1 ns;


  sel <= "11"; //binario
  wait for 1 ns;
  
  wait;

end process;

end tb;