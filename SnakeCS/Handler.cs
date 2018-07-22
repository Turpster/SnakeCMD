using System;
using System.Threading;
namespace SnakeCS
{
    public class Handler
    {
        Player player;

        KeyInput keyInput;
        
        public Handler()
        {
            Random random = new Random();
            player = new Player(new Location((random.Next(Program.WIDTH - 2) + 1), (random.Next(Program.HEIGHT - 2) + 1)), new Vector(1, 0), '+', '~', 4);

            keyInput = new KeyInput(this);
        }

        public void Tick()
        {
            Console.Clear();
            for (int y = 0; y <= Program.HEIGHT; y++)
            {
                for (int x = 0; x <= Program.WIDTH; x++)
                {
                    if (x == 0 || x == Program.WIDTH)
                    {
                        Console.Write('#');
                    }
                    else if (y == 0 || y == Program.HEIGHT)
                    {
                        Console.Write('#');
                    }
                    else if (getEntityHere(x, y) != null)
                    {
                        getEntityHere(x, y).Render(x, y);
                    }
                    else
                    {
                        Console.Write(' ');
                    }
                }
                Console.Write('\n');
            }

            this.player.Tick();
        }

        public void input(ConsoleKeyInfo key)
        {
            if (key.Key == ConsoleKey.UpArrow)
            {
                player.vector.yv = -1;
                player.vector.xv = 0;
            }
            else if (key.Key == ConsoleKey.DownArrow)
            {
                player.vector.yv = 1;
                player.vector.xv = 0;
            }
            else if (key.Key == ConsoleKey.LeftArrow)
            {
                player.vector.yv = 0;
                player.vector.xv = -1;
            }
            else if (key.Key == ConsoleKey.RightArrow)
            {
                player.vector.yv = 0;
                player.vector.xv = 1;
            }
        }

        private Entity getEntityHere(int x, int y)
        {
            if (player.location.x == x && player.location.y == y)
            {
                return this.player;
            }
            foreach (Location loc in player.tailLocs)
            {
                if (x == loc.x && y == loc.y)
                {
                    return this.player;
                }
            }
            return null;
        }
    }
}
