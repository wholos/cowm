#include <wlroots-0.18/wlr/backend.h>
#include <wlroots-0.18/wlr/render/wlr_renderer.h>
#include <wlroots-0.18/wlr/types/wlr_compositor.h>
#include <wlroots-0.18/wlr/types/wlr_output.h>
#include <wlroots-0.18/wlr/types/wlr_output_layout.h>
#include <wlroots-0.18/wlr/types/wlr_xdg_shell.h>
#include <wlroots-0.18/wlr/util/log.h>

struct cowm_state {
    struct wl_display *display;
    struct wl_event_loop *loop;
    struct wlr_backend *backend;
    struct wlr_renderer *renderer;
    struct wlr_compositor *compositor;
    struct wlr_output_layout *output_layout;
};

int main(int argc, char **argv) {
    wlr_log_init(WLR_DEBUG, NULL);

    struct cowm_state state = {0};
    state.display = wl_display_create();
    state.loop = wl_display_get_event_loop(state.display);

    state.backend = wlr_backend_autocreate(state.loop, NULL);
    if (!state.backend) {
        wlr_log(WLR_ERROR, "Failed to create backend");
        return 1;
    }

    state.renderer = wlr_renderer_autocreate(state.backend);
    wlr_renderer_init_wl_display(state.renderer, state.display);

    state.compositor = wlr_compositor_create(state.display, 4, state.renderer);

    state.output_layout = wlr_output_layout_create(state.display);

    if (!wlr_backend_start(state.backend)) {
        wlr_log(WLR_ERROR, "Failed to start backend");
        return 1;
    }

    wlr_log(WLR_INFO, "COWM is running!");
    wl_display_run(state.display);

    wl_display_destroy(state.display);
    return 0;
}
