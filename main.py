import cairo

def draw_face(dc):
    dc.set_source_rgb(0.3, 0.2, 0.1)
    dc.rectangle(0.4, 0.4, 0.1, 0.1)
    dc.fill()

def main():
    size = 1024
    scale = size
    surface = cairo.ImageSurface(cairo.FORMAT_RGB24, size, size)
    dc = cairo.Context(surface)
    dc.set_line_width(0.01)
    dc.set_line_cap(cairo.LINE_CAP_ROUND)
    dc.set_line_join(cairo.LINE_JOIN_ROUND)
    dc.scale(scale, scale)
    dc.set_source_rgb(0, 0, 0)
    dc.paint()
    draw_face(dc)
    surface.write_to_png('output.png')

if __name__ == '__main__':
    main()
