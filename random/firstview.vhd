library IEEE;
use IEEE.std_logic_1164.all;

entity mux_4x1 with is
  port(
    x0,x1,x2,x3: in std_logic;
    sel: in std_logic_vector(1 downto 0);
    z: out std_logic;
  );
end entity;

architecture a of mux_4x1 is
  with sel select
    z <= x0 when "00",
      <= x1 when "01",
      <= x2 when "10",
      <= x3 when others; 
end a;