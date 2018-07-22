using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace SnakeCS
{
    class Player : Entity
    {
        char Tail;
        int TailSize;

        public ArrayList tailLocs = new ArrayList();

        public Player(Location location, Vector vector, char model, char Tail, int TailSize) : base(location, vector, model)
        {
            this.Tail = Tail;
            this.TailSize = TailSize;
        }

        public override void Tick()
        {
            Location oldloc = new Location(base.location.x, base.location.y);
            base.Tick();
            this.AddTail(oldloc);
        }

        public void AddTail(Location location)
        {
            if (tailLocs.Count >= this.TailSize)
            {
                tailLocs.RemoveAt(0);
            }
            tailLocs.Add(location);
        }

        public override void Render(int x, int y)
        {
            base.Render(x, y);
            foreach (Location loc in tailLocs)
            {
                if (loc.x == x && loc.y == y)
                {
                    Console.Write(this.Tail);
                }
            }
        }
    }
}
