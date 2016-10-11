#include <cairo.h>
#include <math.h>

void draw_face();
void draw_text();
void draw_circle();
void fill_with_color();

int main (int argc, char *argv[]) {
		int size = 1024;
		double scale = (double) size;
        cairo_surface_t *surface =
            cairo_image_surface_create (CAIRO_FORMAT_RGB24, size, size);
        cairo_t *cr =
            cairo_create (surface);
		cairo_scale(cr, size, size);
		
		cairo_set_line_width(cr, 0.01);
		cairo_set_line_cap(cr, CAIRO_LINE_CAP_ROUND);
		cairo_set_line_join(cr, CAIRO_LINE_JOIN_ROUND);

		cairo_set_source_rgb(cr, 1, 1, 1);
		
		/*draw_face(cr);	*/
		fill_with_color(cr, 1.0, 1.0, 1.0);		
		draw_circle(cr);
		/*draw_text(cr, "0001");*/
	
        cairo_destroy (cr);
        cairo_surface_write_to_png (surface, "output.png");
        cairo_surface_destroy (surface);
        return 0;
}

void fill_with_color(cairo_t *cr, double r, double g, double b) {
	cairo_set_source_rgb(cr, r, g, b);
	cairo_paint(cr);
	cairo_rectangle(cr, 0, 0, 1, 1);
	cairo_fill(cr);
}

void draw_face(cairo_t *cr) {
		cairo_set_source_rgb(cr, 0.3, 0.2, 0.1);
		cairo_rectangle(cr, 0.4, 0.4, 0.1, 0.1);
		cairo_fill(cr);
}

void draw_circle(cairo_t *cr) {
	double xc = 0.5;
	double yc = 0.5;
	double radius = 0.35;
	double angle1 = 0.0  * (M_PI/180.0);  /* angles are specified */
	double angle2 = 360.0 * (M_PI/180.0);  /* in radians           */
	cairo_set_source_rgb(cr, 0.2, 0.8, 0.1);

	/*cairo_set_line_width (cr, 10.0);*/
	cairo_arc (cr, xc, yc, radius, angle1, angle2);
	/*cairo_stroke (cr);*/
	cairo_fill (cr);
}

void draw_text(cairo_t *cr, char *text) {
		cairo_select_font_face (cr, "serif", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
		cairo_set_font_size (cr, 0.05);
		cairo_set_source_rgb (cr, 0.0, 0.0, 1.0);
		cairo_move_to (cr, 0.01, 0.05);
		cairo_show_text (cr, text);
}
