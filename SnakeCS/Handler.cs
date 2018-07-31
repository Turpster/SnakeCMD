using System;
using System.Threading;
namespace SnakeCS
{
    public class Handler
    {
        Player player;
        Food food;

        int score = 0;

        KeyInput keyInput;
        
        public Handler()
        {
            Random random = new Random();
            player = new Player(new Location(3, 3), new Vector(1, 0), '+', '~', 4);
            food = new Food(new Location(0, 0), new Vector(0, 0), '@');

            Entity.RandomTeleportEntity(player);
            Entity.RandomTeleportEntity(food);

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
                    else if (GetEntityHere(x, y) != null)
                    {
                        GetEntityHere(x, y).Render(x, y);
                    }
                    else
                    {
                        Console.Write(' ');
                    }
                }
                Console.Write('\n');
            }

            this.player.Tick();
            this.food.Tick();

            if (this.player.location.x == this.food.location.x && this.player.location.y == this.food.location.y)
            {
                this.player.TailSize += 1;
                score++;
                Entity.RandomTeleportEntity(food);
            }
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

        private Entity GetEntityHere(int x, int y)
        {
            if (food.location.x == x && food.location.y == y)
            {
                return this.food;
            }
            else if (player.location.x == x && player.location.y == y)
            {
                return this.player;
            }
            else
            {
                foreach (Location loc in player.tailLocs)
                {
                    if (x == loc.x && y == loc.y)
                    {
                        return this.player;
                    }
                }
            }
            return null;
        }
    }
}
